#! /usr/bin/env python

from math import ceil

T = int(input())
for t in range(1, T+1):
    c, f, x = [float(x) for x in input().split()]
    ans = 0.0
    n = ceil(x/c - 1 - 2/f)
    v = 2
    for i in range(n):
        ans += c / v
        v += f
    ans += x / v
    print("Case #{}: {:.7f}".format(t, ans))
    
