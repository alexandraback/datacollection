#! /opt/local/bin/python

import sys, itertools

def getline(file=sys.stdin):
    return file.readline().strip()

def out(s):
    if True:
        print s

def is_recycled(n, m):
    n = str(n)
    m = str(m)
    if len(n) != len(m):
        return False
    for x in range(1, len(n)):
        if n[x:] + n[:x] == m:
            return True
    return False

def recyclings(n):
    n = str(n)
    for x in range(1, len(n)):
        yield int(n[x:] + n[:x])

def solve(casenum):
    answer = 0
    a, b = (int(x) for x in getline().strip().split())
    n = a
    while n < b:
        seen = {}
        for m in recyclings(n):
            if n < m and m <= b and not m in seen:
                seen[m] = 1
                answer += 1
        n += 1
        continue
##         m = n + 1
##         while m <= b:
##             if is_recycled(n, m):
##                 print n, m
##                 answer += 1
##             m += 1
##         n += 1
    print 'Case #%d: %s' % (casenum, answer)

cases = int(getline())
for case in xrange(cases):
    solve(case + 1)
