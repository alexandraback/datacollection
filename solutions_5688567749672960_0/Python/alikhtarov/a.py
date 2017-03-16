#!/usr/bin/env python

import sys

s = {1: 1}
q = [(1, 1)]
x = 0
while len(q):
    a, d = q[0]
    q = q[1:]
    if a + 1 <= 2000000 and a + 1 not in s:
        s[a + 1] = d + 1
        q.append((a + 1, d + 1))
    ra = int(str(a)[::-1])
    if ra not in s:
        s[ra] = d + 1
        q.append((ra, d + 1))

ls = sys.stdin.readlines()
ls = ls[1:]
nc = 1
while len(ls):
    n = int(ls[0])
    ls = ls[1:]

    print "Case #%d: %d" % (nc, s[n])
    nc += 1
