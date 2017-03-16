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

def solve(n):
    seen = set()
    cur = n
    for i in xrange(10000):
        for c in str(cur):
            seen.add(c)
        if len(seen) == 10:
            return cur
        cur += n
    return "INSOMNIA"




t = read_int()
for t in xrange(t):
    n = read_int()
    print "Case #%d: %s" % (t + 1, solve(n))
