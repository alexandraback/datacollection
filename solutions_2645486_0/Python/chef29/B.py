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

def next_one(i,k,E,R,A):
    for e in range(k+1):
        G = A[i] * e
        EE = min(E,k-e+R)
        yield EE,G

def solve(E,R,A):
    D = dict()
    D[E] = 0
    n = len(A)
    ans = 0
    for i in range(n):
        T = dict()
        for k in D:
            ans = max(ans,D[k])
            for kk,v in next_one(i,k,E,R,A):
                if kk in T:
                    T[kk] = max(T[kk],D[k]+v)
                else:
                    T[kk] = D[k]+v 
        D = T
    for k in D:
        ans = max(ans,D[k])
    return ans

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
    E,R,N,A, ans = 5,2,2,(2,1), 12
    check_test(solve(E,R,A), ans, (E,R,A))

    E,R,N,A, ans = 5,2,2,(1,2), 12
    check_test(solve(E,R,A), ans, (E,R,A))

    E,R,N,A, ans = 3,3,4,(4,1,3,5), 39
    check_test(solve(E,R,A), ans, (E,R,A))


def output():
    for case in xrange(1, int(stdin.next()) + 1):
        E,R,N = [int(i) for i in stdin.next().strip().split()]
        A = [int(i) for i in stdin.next().strip().split()]
        # if case in [12]:
        #     print A
        #     break
        ans = solve(E,R,A)
        print 'Case #%d:' % case, ans
        print >>stderr, 'Case #%d:' % case, ans

if __name__ == '__main__':
#    unit_test()
    output()
