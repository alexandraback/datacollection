#!/usr/local/bin/python

import sys
from itertools import groupby

def solve(t):
    pancakes = list(sys.stdin.readline().rstrip())
    groups =  list(groupby(pancakes))
    flips = len(groups) -1 + 1*int(groups[-1][0]=='-')
    print 'Case #{}: {}'.format(t, flips)

if __name__=="__main__":
    T = int(sys.stdin.readline())
    for i in range(1, T+1):
        solve(i)
