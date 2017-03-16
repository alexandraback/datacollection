#!/usr/bin/python

import sys
import re
import math
import string

f = open(sys.argv[1],'r')
num = int(f.readline())

def solve(A, m):
    #print A, m
    if len(m) == 0:
        return 0
    if A > m[0]:
        n = m[1:]
        return solve(A+m[0], n)
    n = m[1:]
    if A > 1:
        return 1+min(solve(2*A-1, m), solve(A, n))
    return 1+solve(A,n)

for i in xrange(num):
    l = f.readline()
    A, N = [int(x) for x in l.split()]
    l = f.readline()
    m = [int(x) for x in l.split()]
    m.sort()
    #print A,N,m
    print 'Case #{}:'.format(i+1), solve(A, m)
