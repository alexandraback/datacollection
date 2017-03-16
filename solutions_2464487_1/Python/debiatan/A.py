#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import math

def read_int(f): return int(f.readline().strip())
def read_l_int(f): return [int(e) for e in f.readline().strip().split()]

def amount(n, r):
    return n*(2*n+2*r-1)

def amount_slow(n, r):
    res = 0
    for i in range(n):
        res += 2*(r+2*i)+1

    return res

def solve(r, t):
    a = float(2)
    b = float(2*r-1)
    c = float(-t)
    sol1 = (-b+math.sqrt(b**2-4*a*c))/(2*a)
    sol2 = (-b-math.sqrt(b**2-4*a*c))/(2*a)
    sol = max(sol1, sol2)
    return int(math.ceil(sol))

if __name__ == '__main__':
    if len(sys.argv)<2:
        print 'Syntax', sys.argv[0], 'fname'
        sys.exit(1)

    f = open(sys.argv[1])
    n_cases = read_int(f)

    for i_case in range(1, n_cases+1):
        r, t = read_l_int(f)
        n = solve(r, t)
        while amount(n, r) > t: n-= 1   # refine solution
        if not n: n = 1
        print 'Case #%d:'%i_case, n
