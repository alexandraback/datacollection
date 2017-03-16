#!/usr/bin/env python
import math

def nth(r, n):
    return int(4 * n + 2 * r -3)

def sum(r, n):
    return int(n * ((2 * r) + (2 * n) - 1))

def bsearch(r, t):
    u = int(math.floor(math.sqrt(t)))
    l = 1
    m = u
    while (u - l) > 3:
        m = int(l + ((u - l) / 2))
        s1 = sum(r, m)
        if (s1 < t):
            l = m
        else:
            u = m + 1

    while True:
        s1 = sum(r, m)
        s2 = sum(r, m + 1)
        if s1 <= t and s2 > t:
            return m
        if s2 <= t:
            m += 1
        else:
            m -= 1

s = raw_input()
T = int(s);
for i in xrange(1, T + 1):
    s = raw_input()
    rs, ts = s.split()
    r = int(rs)
    t = int(ts)
    print "Case #%d: %d" % (i, bsearch(r, t))
