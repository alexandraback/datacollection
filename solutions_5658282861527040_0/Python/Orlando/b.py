#!/usr/bin/env python

t = int(raw_input())

for caseno in xrange(1, t+1):
    a, b, k = map(int, raw_input().split())
    i = 0
    for x in xrange(a):
        for y in xrange(b):
            if x & y < k:
                i += 1
    print "Case #%d: %d" % (caseno, i)
