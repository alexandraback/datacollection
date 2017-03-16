#!/usr/bin/env python

T = input()
for i in xrange(T):
    a, b = [int(k) for k in raw_input().split()]
    r = 0
    for n in xrange(a, b):
        s = str(n)
        t = set()
        for j in xrange(1, len(s)):
            m = int(s[j:] + s[:j])
            if b >= m > n and m not in t:
                t.add(m)
                r += 1

    print 'Case #%d: %d' % (i + 1, r)
