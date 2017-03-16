# -*- coding: utf-8 -*-
import sys,copy,math,heapq,itertools as it,fractions,re,bisect,collections as coll

def convert(a, n):
    a = str(a)
    for i in xrange(n - len(a)):
        a = "0" + a
    return a

def ok(a, b):
    for i in xrange(len(a)):
        if a[-i - 1] == "?":
            continue
        if a[-i - 1] != b[-i - 1]:
            return False
    return True

T = int(raw_input())
for case in xrange(T):
    C, J = raw_input().split()
    mn = 1e10
    for c in xrange(10**len(C)):
        c = convert(c, len(C))
        if not ok(C, c): continue
        for j in xrange(10**len(J)):
            j = convert(j, len(J))
            if not ok(J, j): continue
            if abs(int(c) - int(j)) < mn:
                mn = abs(int(c) - int(j))
                ans1 = c
                ans2 = j
    
    print "Case #%d: %s %s" % (case + 1, ans1, ans2)
