# -*- coding: utf-8 -*-
'''
'''

from collections import deque
#from decimal import Decimal
from sys import stdin, stderr
import copy
import fractions
import heapq
import itertools
import math
#import networkx as nx
import random
import re
import sys

sys.setrecursionlimit(100)

isa = isinstance
INF = 1 << 66

def next_one(k,d,D):
    dx = (1,-1,0,0)
    dy = (0,0,1,-1)
    x,y = k
    for c in 'EWNS':
        if c == 'E':
            i = 0
        if c == 'W':
            i = 1
        if c == 'N':
            i = 2
        if c == 'S':
            i = 3
        X = x + dx[i] * d
        Y = y + dy[i] * d
        yield (X,Y), D[k]+c

def solve(X,Y):
    D = dict()
    D[0,0] = ''
    d = 1
    seen = set()
    seen.add((0,0))
    while D:
        T = dict()
        for k in D:
            x,y = k
            if (x,y) == (X,Y):
                if len(D[k]) <= 500:
                    return D[k]
                else:
                    continue
            for kk,v in next_one(k,d,D):
                if kk not in seen:
                    T[kk] = v
                    seen.add(kk)
        D = T
        d += 1

def check_test(A, B, data='', case=[0]):
    print
    print "test %d:" % case[0]
    print A
#   if abs(A-B) > 1e-9:
    if A != B:
        if data:
            print data
        print '>>>', A
        print '<<<', B
        print "!!!!!!!! FAIL !!!!!!!!"
    else:
        print ":::::::) OK"
    case[0] += 1

def unit_test():
    print
    A,B, ans = 3,4, 'ENWSEN'
    check_test(solve(A,B), ans, (A,B))

    A,B, ans = -3,4, 'ENSWN'
    check_test(solve(A,B), ans, (A,B))    

def output():
    for case in xrange(1, int(stdin.next()) + 1):
        A,B = [int(i) for i in stdin.next().strip().split()]
        # print >>stderr, '--', case
        # if case in [12]:
        #     print >>stderr, A
        #     break
        # print >>stderr, A
        ans = solve(A,B)
        print 'Case #%d:' % case, ans
        print >>stderr, 'Case #%d:' % case, ans

if __name__ == '__main__':
#    unit_test()
    output()
