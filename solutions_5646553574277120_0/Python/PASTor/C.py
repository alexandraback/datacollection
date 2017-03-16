#!/usr/bin/python

import sys, decimal as dec, collections as coll, itertools as itt, fractions as frac, math


T = int(raw_input())
tt = max(T / 10, 1)

for cc in xrange(T):
    print 'Case #{}:'.format(cc + 1),
    if cc % tt == 0:
        print >> sys.stderr, 'Solving: ', (cc + 1) * 100 / T, '%'

    # N = int(raw_input())
    C,D,V = map(int, raw_input().split())

    d = map(int, raw_input().split())

    res = 0

    # print >> sys.stderr, 'd', d

    added = 0 if d[0] == 1 else 1
    cur = 1 if d[0] == 1 else 0
    sum = 1*C

    # print >> sys.stderr, 'cur, added, sum', cur, added, sum

    while sum < V:
        if cur == len(d):
            # print >> sys.stderr, 'End Adding', sum+1
            added += 1
            sum += (sum + 1)*C
        else:
            if sum >= d[cur]-1:
                sum += C*d[cur]
                cur += 1
                # print >> sys.stderr, 'Agrregated'
            else:
                # print >> sys.stderr, 'Adding', sum+1
                added += 1
                sum += (sum + 1)*C

        # print >> sys.stderr, 'cur, added, sum', cur, added, sum

    print added


