#!/usr/bin/env python

T = input()
for i in xrange(T):
    t = [int(k) for k in raw_input().split()]
    n, s, p = t[:3]
    t = t[3:]
    t.sort(reverse=True)
    r = 0
    for x in t:
        if x >= 3 * p - 2 and p >= 1 or p == 0:
            r += 1
        elif s and x >= 3 * p - 4 and p >= 2:
            s -= 1
            r += 1
        else:
            break

    print 'Case #%d: %d' % (i + 1, r)
