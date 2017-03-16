# -*- coding: utf-8 -*-
import sys,copy,math,heapq,itertools as it,fractions,re,bisect,collections as coll

T = int(raw_input())
for case in xrange(1, T + 1):
    J, P, S, K = map(int, raw_input().split())
    jps = set()
    jp = coll.defaultdict(int)
    js = coll.defaultdict(int)
    ps = coll.defaultdict(int)
    ans = []
    for loop in xrange(20):
        for j in xrange(1, J + 1):
            for p in xrange(1, P + 1):
                for s in xrange(1, S + 1):
                    if (j, p, s) in jps: continue
                    if jp[(j, p)] < K and js[(j, s)] < K and ps[(p, s)] < K:
                        ans.append((j, p, s))
                        jp[(j, p)] += 1
                        js[(j, s)] += 1
                        ps[(p, s)] += 1
                        jps.add((j, p, s))
    print "Case #%d: %d" % (case, len(ans))
    for j, p, s in jps:
        print j, p, s
