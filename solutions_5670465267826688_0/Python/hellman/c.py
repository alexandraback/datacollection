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

I, J, K = [2, 3, 4]
LOOKUP = dict(i=I, j=J, k=K)

_mul = [
    [1,  I,  J,  K],
    [I, -1,  K, -J],
    [J, -K, -1,  I],
    [K,  J, -I, -1],
]


def mul(a, b):
    sign = 1
    if a < 0:
        sign *= -1
        a = -a
    if b < 0:
        sign *= -1
        b = -b
    return sign * _mul[a - 1][b - 1]


def take_first(L, X, sl, val, start_pos):
    pos = start_pos
    res = 1
    mxcheck = min(sl * 8, L * X)
    i = 0
    # print "take first mx", mxcheck
    while i < mxcheck:
        res = mul(res, sl[pos])
        pos += 1
        if pos >= L:
            pos -= L
        i += 1
        if res == val:
            return i
        # print "pos", i, ":", res, "?", val
    return None


def fast_exp(sl, e):
    acc = 1
    if e == 0:
        return acc
    for c in sl:
        acc = mul(acc, c)
    res = 1
    while e:
        if e & 1:
            res = mul(res, acc)
        acc = mul(acc, acc)
        e >>= 1
    return res


def solve(L, X, sl):
    ilen = take_first(L, X, sl, I, 0)
    # print ilen
    if ilen is None:
        return False
    jlen = take_first(L, X, sl, J, ilen % L)
    # print jlen
    if jlen is None:
        return False
    used = ilen + jlen
    acc = 1
    pos = (ilen + jlen) % L
    while pos and pos != L:
        acc = mul(acc, sl[pos])
        pos += 1
        used += 1

    assert used % L == 0
    left = X - (used / L)
    if left < 0:
        return False

    acc2 = fast_exp(sl, left)
    res = mul(acc, acc2)
    return res == K


t = read_int()
for i in xrange(1, t + 1):
    L, X = read_ints()
    sl = [LOOKUP[c] for c in read_str()]
    print "Case #%d: %s" % (i, "YES" if solve(L, X, sl) else "NO")

