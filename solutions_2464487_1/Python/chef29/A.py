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

def is_yes(x,r,t):
    y = 2*x-1
    A = x*2*r + y*(y+1)/2
    return A <= t

def solve(r,t):
    lo = 0
    hi = INF
    while lo < hi:
        mid = lo + (hi-lo+1)/2
        if is_yes(mid,r,t):
            lo = mid
        else:
            hi = mid - 1            
    if is_yes(lo,r,t) is False:
        assert(False)
    return lo

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
    r,t, ans = 1,9, 1
    check_test(solve(r,t), ans, (r,t))

    r,t, ans = 1,10, 2
    check_test(solve(r,t), ans, (r,t))

    r,t, ans = 3,40, 3
    check_test(solve(r,t), ans, (r,t))

    r,t, ans = 1,1000000000000000000, 707106780
    check_test(solve(r,t), ans, (r,t))

    r,t, ans = 10000000000000000,1000000000000000000, 49
    check_test(solve(r,t), ans, (r,t))

def output():
    for case in xrange(1, int(stdin.next()) + 1):
        r,t = [int(i) for i in stdin.next().strip().split()]
        ans = solve(r,t)
        print 'Case #%d:' % case, ans
        print >>stderr, 'Case #%d:' % case, ans

if __name__ == '__main__':
#    unit_test()
    output()
