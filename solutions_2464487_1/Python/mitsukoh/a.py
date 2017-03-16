#!/usr/bin/env python3
# coding: utf-8

from math import pi

def f(a0, an):
    n = ((an - a0) / 4) + 1
    return int((a0 + an) * n / 2)

def solve(r, t):
    st = (r+1)*(r+1) - r*r
    lo, hi = 0, 1000 ** 18
    while hi - lo > 1:
        mid = int((lo + hi) / 2)
        need = f(st, st + 4 * (mid - 1))
        if t < need:
            hi = mid
        else:
            lo = mid
    return lo

for i in range(int(input())):
    r, t = list(map(int, input().split(' ')))
    print('Case #{}: {}'.format(i+1, solve(r, t)))
