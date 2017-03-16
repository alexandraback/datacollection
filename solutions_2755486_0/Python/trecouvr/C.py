#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import division
from collections import defaultdict


def split_input(f=int):
    return [ f(x) for x in raw_input().split() ]

runs = input()
for run in xrange(1,runs+1):
    N = input()
    tribes = [ split_input() for _ in xrange(N) ]
    assert N == len(tribes)
    assert all( 8 == len(x) for x in tribes )
    
    attaks = defaultdict(list) # attaks[day] = list<(d, S, Range)>
    for di, ni, wi, ei, si, delta_di, delta_pi, delta_s in tribes:
        for i in xrange(ni):
            attaks[di+delta_di*i].append((di+delta_di*i, si+delta_s*i, (wi+delta_pi*i, ei+delta_pi*i)))
    
    NN = 10**7
    wall = [0] * NN
    mid = NN // 2
    r = 0
    for d,l_attk in attaks.items():
        #print d,l_attk
        for d, S, (w,e) in l_attk:
            for i in xrange(w*2,e*2+1):
                if wall[mid+i] < S:
                    r += 1
                    break
        for d, S, (w,e) in l_attk:
            for i in xrange(w*2,e*2+1):
                wall[mid+i] = max(wall[mid+i], S)
        
    
    print "Case #%d: %r" % (run, r)
