#!/usr/local/bin/pypy

import sys, decimal as dec, collections as coll, itertools as itt, fractions as frac, math

if len(sys.argv) >= 2 and sys.argv[1] == 'debug':
    DEBUG = True
else:
    DEBUG = False

NUM = [
    set('ZERO'),
    set('ONE'),
    set("TWO"),
    set("THREE"),
    set("FOUR"),
    set("FIVE"),
    set("SIX"),
    set("SEVEN"),
    set("EIGHT"),
    set("NINE")
]

# UNIQ = [NUM[i].copy() for i in xrange(10)]
#
# for i in xrange(10):
#     for j in xrange(10):
#         if i != j:
#             UNIQ[i] -= NUM[j]
#
# if DEBUG: print >> sys.stderr, 'NUM', NUM
# if DEBUG: print >> sys.stderr, 'UNIQ', [i for i in xrange(10) if len(UNIQ[i]) >0 ], UNIQ
#
# UNIQ2 = [NUM[i].copy() for i in xrange(10)]
#
# for i in xrange(10):
#     if len(UNIQ[i]) > 0:
#         UNIQ2[i] = set()
#
# for i in xrange(10):
#     if len(UNIQ[i]) == 0:
#         for j in xrange(10):
#             if i != j and len(UNIQ[j]) == 0:
#                 UNIQ2[i] -= NUM[j]
#
# if DEBUG: print >> sys.stderr, 'UNIQ2', [i for i in xrange(10) if len(UNIQ2[i]) >0 ], UNIQ2



_T = int(raw_input())
_tt = max(_T/10, 1)

for _cc in xrange(_T):
    print 'Case #{}:'.format(_cc+1),
    if _cc % _tt == 0:
        print >>sys.stderr, 'Solving: ', (_cc+1)*100/_T, '%'

    s = raw_input()

    d = coll.defaultdict(int)

    for e in s:
        d[e] += 1


    res = []

    for i in [0, 2, 4, 6, 8, 1, 3, 5, 7, 9]:
        m = 10**16
        for e in NUM[i]:
            m = min(m, d[e])

        res.extend([str(i)]*m)

        for e in NUM[i]:
            d[e] -= m

    print ''.join(sorted(res))


