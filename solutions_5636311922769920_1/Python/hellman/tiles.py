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
epr = lambda *args: sys.stderr.write(" ".join(str(x) for x in args) + "\n")
die = lambda *args: pr(*args) ^ exit(0)

read_str = raw_input
read_strs = lambda: raw_input().split()
read_int = lambda: int(raw_input())
read_ints = lambda: map(int, raw_input().split())
read_float = lambda: float(raw_input())
read_floats = lambda: map(float, raw_input().split())

"---------------------------------------------------------------"

def solve(width, depth, tolook):
    if depth == 1:
        if width != tolook:
            return
        return range(1, width + 1)

    need = []
    for b in range(0, width, 2):
        if b == width - 1:
            need.append(b * width)
        else:
            need.append(b * width + b + 1)

    if tolook >= len(need):
        return [x + 1 for x in need]

t = read_int()
for t in xrange(t):
    K, C, S = read_ints()
    print "Case #%d:" % (t + 1),
    res = solve(K, C, S)
    if res is None:
        print "IMPOSSIBLE"
    else:
        print " ".join(map(str, res))
