#!/usr/bin/python

from itertools import *

def solve(S):
    adj = 0
    std = 0
    for (s, i) in zip(S, count()):
        if std < i:
            adj += i - std
            std = i
        std += s
    return adj

T = int(raw_input())
for i in range(T):
    a, b = raw_input().split(' ')
    print "Case #%i: %s" % (i+1, solve(map(int, b)))
