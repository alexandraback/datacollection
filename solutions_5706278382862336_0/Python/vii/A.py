import sys
from collections import *
from fractions import gcd

def r():
    return sys.stdin.readline().rstrip()

T = int(r())

def is_pow_2(a):
    return 0 == a & (a-1)

def solve():
    frac = r().split('/')
    a = int(frac[0])
    b = int(frac[1])
    g = gcd(a, b)
    a /= g
    b /= g

    if not is_pow_2(b):
        return "impossible"
    for i in range(1,41):
        if a*2 >= b:
            return i
        a *= 2

    return "impossible"

for t in range(1, T+1):
    print("Case #%d: %s" %( t, solve()))
