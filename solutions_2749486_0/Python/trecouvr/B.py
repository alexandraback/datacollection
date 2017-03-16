#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import division

def split_input(f=int):
    return [ f(x) for x in raw_input().split() ]

runs = input()
for run in xrange(1,runs+1):
    X,Y = split_input()
    
    if X < 0:
        X = -X
        a = 'WE'
    else:
        a = 'EW'
    
    if Y < 0:
        Y = -Y
        b = 'NS'
    else:
        b = 'SN'
    
    s = ''
    if X != 0:
        s += a*(X-1)+a[0]
    if Y != 0:
        s += b*(Y)
    
    assert len(s) < 500
    
    print "Case #%d: %s" % (run, s)
