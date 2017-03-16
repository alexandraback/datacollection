//
//  main.cpp
//  CodeJam
//
//  Created by Sercan Tutar on 4/13/13.
//  Copyright (c) 2013 Sercan Tutar. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <fstream>
#include <math.h>

#define LOG_ERROR std::cout << "ERROR IN LINE: " << __LINE__ << std::endl
#define NO_TYPE long long

NO_TYPE A, B;

// 1234567
// 2000000 - 9999999 (9-1)*10ˆ3
// 1300000 - 1999999 (9-2)*10ˆ2
// 1240000 - 1200000 (9-3)*10ˆ1
// 1235000 - 1239999 (9-4)*10ˆ0
// 1234567 +1 if this is palindrome

// 23456
// 10000 - 19999 (2-1)*10ˆ2
// 20000 - 22999 3*10ˆ1
// 23000 - 23399 4*10ˆ0
// 23456 +1 if this is palindrome

int numberOfDigits(NO_TYPE number)
{
    int digits = 0;
    while (number >= 1) {
        number /= 10;
        digits++;
    }
    return digits;
}

int digitAt(NO_TYPE number, int d)
{
    for(int i=0; i<d; i++)
        number /= 10;
    return number % 10;
}

bool isPalindrome(NO_TYPE number)
{
    int digitCount = numberOfDigits(number);
    for (int i=0; i<digitCount/2; i++)
        if (digitAt(number, i) != digitAt(number, digitCount-1-i))
            return false;
    return true;
}

void solve()
{
    int total = 0;
    NO_TYPE sqrtA = (NO_TYPE)ceil(sqrt((double)A));
    NO_TYPE sqrtB = (NO_TYPE)floor(sqrt((double)B));
    for (NO_TYPE i=sqrtA; i<=sqrtB; i++)
        if (isPalindrome(i) && isPalindrome(i*i))
            total++;
    std::cout << total << std::endl;
}

int main(int argc, const char * argv[])
{
    int noOfCases;
    std::cin >> noOfCases;
    for (int i = 0; i < noOfCases; i++) {
        std::cin >> A >> B;
        
        std::cout << "Case #" << i+1 << ": ";
        solve();
    }
    
    return 0;
}
