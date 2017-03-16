#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
#import numpy as np
#import itertools

def read_int(f): return int(f.readline().strip())

def conscons(s):
    res = 0
    max_res = 0
    for c in s:
        if c not in ('a', 'e', 'i', 'o', 'u'):
            res += 1
        else:
            max_res = max(max_res, res)
            res = 0
    return max(max_res, res)

def solve(s, n):
    res = 0
    for i in range(len(s)-n+1):
        for j in range(i+n, len(s)+1):
            if conscons(s[i:j])>=n:
                res += 1
    return res

if __name__ == '__main__':
    if len(sys.argv)<2:
        print 'Syntax', sys.argv[0], 'fname'
        sys.exit(1)

    f = open(sys.argv[1])
    n_cases = read_int(f)

    for i_case in range(1, n_cases+1):
        s, n = f.readline().strip().split()
        n = int(n)
        print 'Case #%d:'%i_case, solve(s, n)
        """
        if possible(case): print 'YES'
        else: print 'NO'
        """
