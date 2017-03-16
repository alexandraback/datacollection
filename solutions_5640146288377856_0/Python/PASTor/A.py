#!/usr/bin/python

import sys, decimal as dec, collections as coll, itertools as itt, fractions as frac, math


T = int(raw_input())
tt = max(T / 10, 1)

for cc in xrange(T):
    print 'Case #{}:'.format(cc + 1),
    if cc % tt == 0:
        print >> sys.stderr, 'Solving: ', (cc + 1) * 100 / T, '%'

    # N = int(raw_input())
    R,C,W = map(int, raw_input().split())

    rest = W

    res = C / W
    res += 1 if W*res < C else 0

    if W*res >= C:
        rest -= 1

    # print >> sys.stderr, 'First shoots', res

    res = res * R

    # print >> sys.stderr, 'Shoots times rows', res


    res += rest

    # print >> sys.stderr, '+ search', res

    print res


