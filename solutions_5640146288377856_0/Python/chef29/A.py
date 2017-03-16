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
inf = 1 << 66

def solve(R,C,W):
    if W == 1:
        return R*C
    L = W
    if C - L >= W:
        ans = R + solve(R,C-L,W)
    else:
        ans = R-1
        ans += W + (1 if C > W else 0)
    return ans

def output():
    for case in xrange(1, int(stdin.next()) + 1):
        R,C,W = [ int(a) for a in stdin.next().strip().split() ]
        print >>stderr, 'Case #%d:' % case
        # if case in [12]:
        #     print >>stderr, A
        #     break
        print >>stderr, R,C,W
        ans = solve(R,C,W)
        print 'Case #%d:' % case, ans
#        print >>stderr, 'Case #%d:' % case, ans

#if __name__ == '__main__':
output()

