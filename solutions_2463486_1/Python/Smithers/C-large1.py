#!/usr/bin/env python3

# Solution to Problem C. Fair and Square in Python 3.

from bisect import bisect_left, bisect_right

# Values pre-computed by C-large1-precomp.py
fsnos = [
    1,
    4,
    9,
    121,
    484,
    10201,
    12321,
    14641,
    40804,
    44944,
    1002001,
    1234321,
    4008004,
    100020001,
    102030201,
    104060401,
    121242121,
    123454321,
    125686521,
    400080004,
    404090404,
    10000200001,
    10221412201,
    12102420121,
    12345654321,
    40000800004,
    1000002000001,
    1002003002001,
    1004006004001,
    1020304030201,
    1022325232201,
    1024348434201,
    1210024200121,
    1212225222121,
    1214428244121,
    1232346432321,
    1234567654321,
    4000008000004,
    4004009004004
]

for c in range(int(input())):
    a, b = [int(s) for s in input().split()]
    i = bisect_left(fsnos, a)
    j = bisect_right(fsnos, b)
    print("Case #{}: {}".format(c+1, j - i))
