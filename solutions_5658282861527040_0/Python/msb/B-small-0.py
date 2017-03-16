#!/usr/bin/env python

def solve(a, b, k):
    count = 0
    for i in xrange(a):
        for j in xrange(b):
            if i & j < k:
                count += 1
    print count

for case in xrange(int(raw_input())):
    print "Case #%d:" % (case+1),
    a, b, k = map(int, raw_input().split())
    solve(a, b, k)
