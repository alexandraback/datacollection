#!/usr/bin/python
import sys, collections

data = file(sys.argv[1]).read().splitlines()

T = int(data.pop(0))

def calc( C, F, X, R, t ):
    m = X/ R

    while 1:
        p = t+(X/R)
        if p > m:
            break
        m = p
        t = t + (C / R)
        R = R + F
    return m


for numcase in xrange(1,T+1):
    print 'Case #%d:' % numcase,
    (C, F, X) = [ float(x) for x in data.pop(0).split() ]
    print calc(C,F,X,2,0.0)



