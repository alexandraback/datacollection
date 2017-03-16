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

def next_one(x,seen):
    a = x+1
    b = str(x)[::-1]
    b = int(b)
    if a not in seen:
        seen.add(a)
        yield a
    if b not in seen:
        seen.add(b)
        yield b

def solve(N):
    D = dict()
    D[1] = 1
    ans = 0
    seen = set([1])
    while True:
        ans += 1
        T = dict()
        for x in sorted(D,reverse=True):
            if x == N:
                return ans;
            for y in next_one(x,seen):
                T[y] = 1
        D = T

def output():
    for case in xrange(1, int(stdin.next()) + 1):
        N = int(stdin.next().strip())
        # print >>stderr, '--', case
        # if case in [12]:
        #     print >>stderr, A
        #     break
        # print >>stderr, A
        ans = solve(N)
        print 'Case #%d:' % case, ans
        print >>stderr, 'Case #%d:' % case, ans

#if __name__ == '__main__':
# unit_test()
output()
