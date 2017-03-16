#!/usr/bin/python

import sys, decimal as dec, collections as coll, itertools as itt, fractions as frac, math


eps = 1e-6


def occurrences(s, ss):
    # print >> sys.stderr, 's, ss', s, ss
    count = start = 0
    while True:
        start = s.find(ss, start) + 1
        if start > 0:
            count+=1
        else:
            return count



T = int(raw_input())
tt = max(T / 10, 1)

for cc in xrange(T):
    print 'Case #{}:'.format(cc + 1),
    if cc % tt == 0:
        print >> sys.stderr, 'Solving: ', (cc + 1) * 100 / T, '%'

    # N = int(raw_input())
    K, L, S = map(int, raw_input().split())
    keys = raw_input().strip()
    target = raw_input().strip()

    res = 0
    llk = len(keys)

    p = {}
    # k = set()
    for key in keys:
        c = p.get(key, 0.0)
        p[key] = c+1.0
        # k.add(key)

    # pt = 0
    # for i in xrange(len(target)):
    #     pt = pt * p[target[i]] / llk

    occ = {}
    ll = 0
    maxx = 0
    for test in itt.product(keys, repeat=S):
        # print >> sys.stderr, 'test, target', test, target

        o = occurrences(''.join(test), target)

        # print >> sys.stderr, 'o', o

        occ[o] = occ.get(o, 0.0) + 1.0
        ll += 1

        if maxx < o:
            maxx = o
            # print >> sys.stderr, 'Max changes', maxx

    # print >> sys.stderr, 'occ, , maxx, ll', occ, maxx, ll


    average = 0
    for o in occ:
        average += o * occ[o]/ll


    print maxx - average


