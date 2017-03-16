#!/usr/bin/env python

import sys

cache = {}

def tos(i):
    if i in cache:
        return cache[i]
    ii = i
    s = ""
    while i > 0:
        s = str(i % 10) + s;
        i = i // 10

    n = len(s)
    t = s;
    mmm = s;
    for i in xrange(n):
        t = t[1:] + t[0]
        mmm = min(t, mmm)
    cache[ii] = mmm

    return mmm


for i, line in enumerate(sys.stdin.readlines()[1:]):
    A, B = [int(x) for x in line.split()]
    ret = 0
    strings = {}
    for n in xrange(A, B+1):
        t = tos(n)
        if t not in strings:
            strings[t] = 0
        strings[t] += 1

    ret = 0
    for k in strings:
        ret += strings[k] * (strings[k] - 1) // 2
    
    print "Case #%d: %d" % (i+1, ret)
    
        

