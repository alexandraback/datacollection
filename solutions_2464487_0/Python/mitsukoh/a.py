#!/usr/bin/env python3
# coding: utf-8

from math import pi

def f(r):
    return r * r

def solve(r, t):
    r += 1
    ret = 0
    while t > 0:
        t -= f(r) - f(r-1)
        if t >= 0:
            ret += 1
        r += 2
    return ret

for i in range(int(input())):
    r, t = list(map(int, input().split(' ')))
    print('Case #{}: {}'.format(i+1, solve(r, t)))
