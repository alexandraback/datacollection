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

CHOOSER_WIN = "WIN"
CHOOSER_LOSE = "LOSE"

"""
#-w--#
|    |
|    |
h    |
|    |
|    |
|    |
#----#
"""


def solve_angle(x, w, h, uw, uh):
    space = uw * uh - uw - uh + 1
    for down in xrange(space + 1):
        good = True
        for add_rows in xrange(h - uh + 1):
            size = add_rows * w + down
            if size % x == 0:
                good = False
                break
        if good:
            return CHOOSER_WIN
    return CHOOSER_LOSE


def solve(x, w, h):
    # not divisible
    if (w * h) % x:
        return CHOOSER_WIN
    # free
    if x < w:
        return CHOOSER_LOSE
    # long vertical
    if x >= h + 1:
        return CHOOSER_WIN
    # angle simple
    a = w + 1
    b = 1 + (x - a)
    if b >= w + 1:
        return CHOOSER_WIN
    # print >>sys.stderr, "ANGLE"
    # angle
    a = w
    b = 1 + (x - a)
    if b < w:
        return CHOOSER_LOSE
    return solve_angle(x, w, h, a, b)


t = read_int()
for i in xrange(1, t + 1):
    x, w, h = read_ints()
    if h < w:
        w, h = h, w
    res = solve(x, w, h)
    print >>sys.stderr, "    :: Case", i, ":", "x", x, ", r", w, ", c", h, ".", res
    print "Case #%d: %s" % (i, "RICHARD" if res == CHOOSER_WIN else "GABRIEL")

