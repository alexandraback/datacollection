#! /usr/bin/env python3

import sys

def R(str_ing):
    return "".join(reversed(str_ing))

def counter(N):
    if N<21:
        return N
    S = str(N)
    nnR = (len(S)+1)//2
    nnL = len(S)-nnR

    # if 1000000000...abcdeffg, just count down to  99999..999
    if int(R(S[:nnL]))==1:
        return int(S[-nnR:])+1+counter(10**(len(S)-1)-1)

    # if ...0000000000
    if int(S[-nnR:])==0:
        return 1 + counter(N-1)

    return ( 1 # 1 for swap
             + int(S[-nnR:]) - 1
             + counter( int("1" + ("0"*(nnR-1)) 
                            + R(S[:nnL]) ) ) )

number_of_test_cases = int(sys.stdin.readline())
for test_no in range(1, number_of_test_cases+1):
    N = int(sys.stdin.readline())
    print("Case #{}: {}".format(test_no,counter(N)))
