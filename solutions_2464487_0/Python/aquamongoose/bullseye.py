#!/usr/bin/env python
import sys
import math

testcases = int(input())
for testcase in range(testcases):
    print('Case #{}: '.format(testcase+1), end='')
    r, t = [int(x) for x in input().split()]
    r += 1
    # r is the first big radius, t is mL of paint.
    lo = 0
    hi = 10**20
    while lo+1 < hi:
        n = (lo+hi)//2
        if t >= (2*(r+n)*(n+1))-(n+1):
            lo = n
        else:
            hi = n
    print(lo+1)
