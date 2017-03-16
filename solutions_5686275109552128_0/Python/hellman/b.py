#!/usr/bin/env python
#-*- coding:utf-8 -*-

import sys, math, random, operator
from string import ascii_lowercase
from string import ascii_uppercase
from fractions import Fraction, gcd
from decimal import Decimal, getcontext
from itertools import product, permutations, combinations
from Queue import Queue, PriorityQueue
from collections import deque, defaultdict, Counter
getcontext().prec = 100

MOD = 10**9 + 7
INF = float("+inf")

if sys.subversion[0] != "CPython":  # PyPy?
    raw_input = lambda: sys.stdin.readline().rstrip()
pr = lambda *args: sys.stdout.write(" ".join(str(x) for x in args) + "\n")

read_str = raw_input
read_strs = lambda: raw_input().split()
read_int = lambda: int(raw_input())
read_ints = lambda: map(int, raw_input().split())
read_float = lambda: float(raw_input())
read_floats = lambda: map(float, raw_input().split())

"---------------------------------------------------------------"


def solve(d, arr):
    arr.sort(reverse=True)
    ans = arr[0]
    for p in xrange(1, 1001):
        ops = 0
        for x in arr:
            if x <= p:
                break
            ops += (x - 1) / p
        ans = min(ans, ops + p)
    return ans


t = read_int()
for i in xrange(1, t + 1):
    d = read_int()
    arr = read_ints()
    print "Case #%d: %d" % (i, solve(d, arr))

