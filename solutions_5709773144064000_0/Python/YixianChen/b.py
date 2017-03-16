#!/usr/bin/env python

import sys, operator as op, itertools as itt, math


f = sys.stdin
T = int( f.next() )

for case in xrange ( 1, T+1 ):
    v = 2.0
    C, F, X = map ( float, f.next().strip().split() )
    def better ( v, C, F, X ):
        return (X/(v+F)) - ((X-C)/v) < 0
    t = 0.0
    while better ( v, C, F, X ):
        #print t, v, C, F, X
        #print X/(v+F), (X-C)/v
        t += (C/v)
        v += F
    t += X/v
    print "Case #{0}: {1:0.7f}".format ( case, t )


