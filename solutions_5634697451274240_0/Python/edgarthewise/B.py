import sys
#import numpy as np
#from numpy import *

def getInt(f):
    return int(f.readline().strip())

def getLine(f):
    return f.readline().strip()

def getInts(f):
    return [int(i) for i in f.readline().strip().split()]

#with open('/home/edgar/B.in') as f:
with sys.stdin as f:
    T = getInt(f)
    for t in xrange(1,T+1):
        P = getLine(f) + '+'
        print 'Case #%d:' % t, sum(P[i] != P[i+1] for i in range(len(P)-1))
        sys.stdout.flush()

