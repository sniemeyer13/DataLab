/* 
 * CS:APP Data Lab 
 * 
 * Sarah Niemeyer 100027519
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
//or
  return ~(~x & ~y);
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) { 
//01010101000000000000000000000000 
  int a = 85<<24; 
//00000000010101010000000000000000
  int b = 85<<16;
//00000000000000000101010100000000
  int c = 85<<8;
//00000000000000000000000001010101
  int d = 85;
//mask them together using or and you get: 01010101010101010101010101010101
  return (a|b|c|d);
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
// -1 in binary is 11111111111111111111111111111111 
//binary for zero is 00000000000000000000000000000000
//so if you take the opposite of zero in binary, you get -1! 
  int a = 0;
  return ~a;
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {  
//make a mask 10101010 (where all the odd bits are set to 1)
  int a = 85|85<<8|85<<16|85<<24;
  
//mask it over the number and exclusive or it with the mask, this will get you
//0 if the number is the same as the mask, or 1 if the number is different from the mask
//bang this to get the opposite (1 for true, 0 for false)
  return !((a & x) ^ a);
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
	//create a mask of 101010101010101010101010
    int a = 170|170<<8|170<<16|170<<24;
    //and it with the number to get the mask
    //if there is a one in an odd spot, you bang it and then it will = 0 then 
    //bang it again to get it to be 1 (true)
    
    //if there is no one in an odd spot, it will equal zero, so you bang it
    //and it will equal one and bang it again and it will equal zero (false)
    return !!(a & x);
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */

int byteSwap(int x, int n, int m) {
	//make two masks with all zeroes and just 1's in the place where you
	//want to swap (we will tilda this later to make it a proper mask)
	int Mask, Nask, swap_n, swap_m, mask, ntom, mton, nmswitched;
	Mask = 255 << (m<<3);
	Nask = 255 << (n<<3);
	
	//pull out the individual bytes you want to swap
	swap_n = Nask&x;
	swap_m = Mask&x;
	
	//make the mask a real mask where zeroes are in the spots where you want to replace
	mask = ~(Mask|Nask);
	
	//turn x into the same number with zeroes in the places you want to swap
	x = x&mask;
	
	//shift n over
	ntom = ((swap_n>>(n<<3))&255)<<(m<<3);
	mton = ((swap_m>>(m<<3))&255)<<(n<<3);
	
	//make something with all zeroes except n and m (and n and m are swtiched)
	nmswitched = ntom|mton;
	
	//add the original number with the 0's in the swap spots with the thing
	//that's all zeroes except n and m and n and m are switched
	return x+nmswitched;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  //find the sum of the variables
  int sum = x + y;
  
  //figure out the sign of x and y and their sum (1 being negative, 0 being positive)
  int xsign = x >> 31;
  int ysign = y >> 31;
  int xysign = sum >> 31;
  
  //if the signs are different, it doesn't overflow and the function will return 0
  //likewise, if the signs are the same but it doesn't overflow and the function will return 0
  //otherwise the function will return 1
  return !(~(ysign ^ xsign) & (ysign ^ xysign));
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {

//x?y:z = if x then y, else z


//make x into only 1's and 0's
//!2 = 0000000000000
//!!2 = 1111111111111
//~!!2 = 00000000000000
//~!!2+1 = 0000000000001 = 1 = true
//!0 = 1111111111111
//!!0 = 000000000000000000
//~!!0 = 11111111111111111
//~!!0 = OVERFLOW = 0
//therefore turning x into just zero if it's zero and just one if it's not zero
	x = !!x;
	x = ~x+1; 

//it's either x AND y OR NOT x AND z
//if x is zero (not true), use z 
//if x is not zero (true), use y
	return (x & y) | (~x & z); 
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x){
	 
 //first make sure that the first digit is 3 (0011)
 //15 = 1111
 int three = !(3^((~(15<<28))&(x>>4)));
 
 //30-37 is (0011 0xxx) so check to see if the first digit is zero. if so, return true
 int firstzero = !(x&8);
 
 //now we check to see if it's 38
 //57 is hex 39 (mixed this up....)
 int thirtyeight = !(x^57);
 
 //and then check to see if it's 39
 //58 is hex 38 (mixed this up...)
 int thirtynine = !(x^56);
 
 int answer = (three & firstzero)|thirtyeight|thirtynine; 
 
 return answer; 
}
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
  
  //make the mask 11111111
  int mask = 255;
  
  //shift the mask to the location of the desired byte, and then ~ it so
  //the mask is zeroes and not 1's
  mask = ~(mask << (n<<3));
  
  //shift c over to the location you're trying to replace
  c = c << (n<<3); 
  
  //use the mask on the original number, and add c
  return (x & mask) + c; 

}
/* reverseBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: reverseBits(0x11111111) = 0x88888888
 *            reverseBits(0xdeadbeef) = 0xf77db57b
 *            reverseBits(0x88888888) = 0x11111111
 *            reverseBits(0)  = 0
 *            reverseBits(-1) = -1
 *            reverseBits(0x9) = 0x90000000
 *  Legal ops: ! ~ & ^ | + << >> and unsigned int type
 *  Max ops: 90
 *  Rating: 4
 */
int reverseBits(int x) {
int a,b,c,pairs,doubles,nibbles,bytes;


//pairs mask = 01010101010101... and is used to swap two things next to eachother
  a=85;
  b=a<<8;
  a=a+b;
  c=a<<16;
  pairs=a+c;

//doubles mask = 001100110011... and is used to swap pairs
  a=51;
  b=a<<8;
  a=a+b;
  c=a<<16;
  doubles=a+c;

//nibbles mask = 0000111100001111.... and is used to swap nibbles (4-bit)
  a=15;
  b=a<<8;
  a=a+b;
  c=a<<16;
  nibbles=a+c;

//bytes mask = 0000000011111111... and is used to swap bytes
  bytes=255+(255<<16);

  

//swaps bits next to one another
//x shifted over one, AND 10000000000000 AND 1010101010101010101
//OR  x and 10101010101010 shifted over one
  x = (((x >> 1)&(~(1<<31))) & pairs) | ((x & pairs) << 1);

//swaps pairs next to one another
  x = (((x >> 2)&(~(3<<30))) & doubles) | ((x & doubles) << 2);

//swaps nibbles
  x = (((x >> 4)&(~(15<<28))) & nibbles) | ((x & nibbles) << 4);

//swaps bytes
  x = (((x >> 8)&(~(255<<24))) & bytes) | ((x & bytes) << 8);

//cuts the final number in half and switches sides
  x = ((x >> 16)&(~((255+(255<<8))<<16))) | ( x << 16);
 
 return x;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {	
	
//same as addOk
  int sum = x + y;
  int xsign = x >> 31;
  int ysign = y >> 31;
  int xysign = sum >> 31;
  int overflow = (~(xsign ^ ysign)) & (xsign ^ xysign);
  
  //the positive overflow occured if the sign of x is negative and overflow occured
  int positive = overflow & (~(xsign ^ 0));
  
  //negative overflow occured if the sign of x is positive and overflow occured
  int negative = ~(overflow & (~(xsign^0)));
  
  //1000000000000000000000000
  int minimum = 1 << 31;
  
  //0111111111111111111111111
  //largest positive number
  int maximum = ~minimum;
  
  int final = (~overflow & sum) | (overflow & ((positive & maximum) | (negative & minimum)));
  return final;
}
/*
 * Extra credit
 */
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
	return 2;
 }
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  return 2;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  return 2;
}
