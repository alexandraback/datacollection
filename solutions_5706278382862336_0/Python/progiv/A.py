#!/usr/bin/env python3
from fractions import gcd

def answer(a, b):
    greatestCD = gcd(a, b)
    b = b // greatestCD
    a = a // greatestCD
    binA = bin(a)[2:]
    binB = bin(b)[2:]
    if binB.count('1') > 1:
        return "impossible"
    return len(binB)-len(binA)

T = int(input())
for case in range(1, T+1):
    a, b = map(int, input().strip().split("/"))
    print("Case #{}: {}".format(case, answer(a, b)))
