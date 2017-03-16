#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import numpy as np

def read_case(f):
    n, m = [int(e) for e in f.readline().strip().split()]
    l = [[int(e) for e in f.readline().strip().split()] for i in range(n)]
    return np.array(l, dtype='int')

def possible(case):
    hs = sorted(set(case.flat))     # heights
    for h in hs:
        pos = np.where(case == h)
        for x,y in np.array(pos).T:
            v = case[x, y]
            if any(case[x, :]>v) and any(case[:, y]>v):
                return False

    return True

if __name__ == '__main__':
    if len(sys.argv)<2:
        print 'Syntax', sys.argv[0], 'fname'
        sys.exit(1)

    f = open(sys.argv[1])
    n_cases = int(f.readline().strip())

    for i in range(1, n_cases+1):
        case = read_case(f)
        print 'Case #%d:'%i,
        if possible(case): print 'YES'
        else: print 'NO'
