# -*- coding: utf-8 -*-
'''
Key Words:

diamond inheritance

Rules:

A class diagram is said to contain a diamond inheritance if there
exists a pair of classes X and Y such that there are AT LEAST two
different inheritance paths from X to Y. The above class diagram
is a classic example of diamond inheritance. Your task is to
determine whether or not a given class diagram contains a diamond
inheritance.

Example:

Observations:

Goal:

Your task is to determine whether or not a given class diagram
contains a diamond inheritance.

Input:

The first line of each test case gives the NUMBER OF CLASSES in this
diagram, N. The classes are numbered from 1 to N. N lines follow.
The ith line starts with a non-negative integer Mi indicating the
number of classes that class i inherits from. This is followed by
Mi distinct positive integers each from 1 to N representing those
classes. You may assume that:

If there is an inheritance path from X to Y then there is no
inheritance path from Y to X.

A class will never inherit from itself.

3
1 2
1 3
0

Limits

Output:
'''

from collections import deque
from decimal import Decimal
import copy
import fractions
import heapq
import itertools
import math
import random
import re
import sys

sys.setrecursionlimit(100)

stdin, stderr = sys.stdin, sys.stderr

INF = sys.maxint

def DFS(S,next_node):
    L = [ (S,0) ]
    seen = dict([(S,S)])
    while L:
        u,d = L.pop()
        for v in next_node(u):
            if v not in seen:
                seen[v] = u
                L.append((v,d+1))
            else:
                return True
    return False

def solve(A):
    G = dict()
    for i in range(len(A)):
        G[i+1] = A[i][1:]
    def next_node(u):
        if u in G:
            for v in G[u]:
                yield v
    for u in G:
        if DFS(u,next_node):
            return 'Yes'
    return 'No'

def check_test(A, B, case=[0]):
    print "test %d:" % case[0]
    print A
    if A != B:
        print '>>>', A
        print '<<<', B
        print "!!!!!!!! FAIL !!!!!!!!"
    else:
        print ":::::::) OK"
    case[0] += 1

def unit_test():
    print
    A = [ [ 1,2], [1,3], [0] ]
    check_test(solve(A), 'No')

    A = [
        [2,2,3],
        [1,4],
        [1,5],
        [1,5],
        [0],]
    check_test(solve(A), 'Yes')

    A = [
        [2,2,3],
        [1,3],
        [0],
        ]
    check_test(solve(A), 'Yes')

    A = [ [1,0], [2,0] ]
    check_test(solve(A), 'No')

def output():
    for case in xrange(1, int(stdin.next()) + 1):
        N = int(stdin.next().strip())
        A = list()
        for _ in range(N):
            A.append([int(i) for i in stdin.next().strip().split()])
        # if case in [12]:
        #     print A
        #     break
        print 'Case #%d:' % case, solve(A)

if __name__ == '__main__':
#    unit_test()
    output()

