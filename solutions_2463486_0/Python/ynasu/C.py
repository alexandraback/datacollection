#!/usr/bin/env python

import sys

lst = []

def isFair(n):
    return str(n) == ''.join(reversed(str(n)))

for n in xrange(3 * 10 ** 6):
    if isFair(n) and isFair(n ** 2):
        lst.append(n ** 2)

def count(N):
    l = 0
    u = len(lst)
    while l < u:
        m = (l + u) / 2
        if N < lst[m]:
            u = m
        else:
            l = max(m, l + 1)
    return l

def solve(A, B):
    return str(count(B) - count(A - 1))

def readInts():
    return [ int(s) for s in sys.stdin.readline().split() ]

T = int(sys.stdin.readline())
for t in xrange(T):
    inputs = readInts()
    A = inputs[0]
    B = inputs[1]
    res = solve(A, B)
    print "Case #%d: %s" % (t + 1, res)
