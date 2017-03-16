#!/usr/bin/env python3

from math import sqrt, floor
import sys

# credits http://code.activestate.com/recipes/577821-integer-square-root-function/
def isqrt(x):
    if x < 0:
        raise ValueError('square root not defined for negative numbers')
    n = int(x)
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y

def bull(r, t):
    D = (2*r - 1)*(2*r - 1) + 8*t

    n1 = floor((1 - 2*r + isqrt(D)) / 4)
    return n1

T = int(sys.stdin.readline().strip())

for i in range(T):
    r, t = [int(_) for _ in sys.stdin.readline().strip().split()]
    print("Case #{}: {}".format(i+1, bull(r, t)))

