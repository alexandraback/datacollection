#!/usr/local/bin/python

import sys
from itertools import groupby

def solve(t):
    K, C, S = map(int, sys.stdin.readline().rstrip().split())
    checks = ' '.join(str(i) for i in range(1, K+1))
    print 'Case #{}: {}'.format(t, checks)

if __name__=="__main__":
    T = int(sys.stdin.readline())
    for i in range(1, T+1):
        solve(i)
