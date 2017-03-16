#!/usr/bin/python

from bisect import bisect, bisect_left
from sys import argv

limit = 10**7+1
if len(argv) == 2:
    limit = int(argv[1]) + 1

def ispalin(x):
    s = str(x)
    return s == s[::-1]

palins = [x for x in xrange(1, limit) if ispalin(x)]
#print len(palins)
fairs = [x*x for x in palins if ispalin(x*x)]
#print len(fairs)

def get():
    a, b = map(int, raw_input().strip().split())
    return bisect(fairs, b) - bisect_left(fairs, a)

n = input()
for x in xrange(n):
    print 'Case #%d: %s' % (x+1, get())
