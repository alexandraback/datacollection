import sys
#import numpy as np
#from numpy import *

def getInt(f):
    return int(f.readline().strip())

def getLine(f):
    return f.readline().strip()

def getInts(f):
    return [int(i) for i in f.readline().strip().split()]

#with open('/home/edgar/A.in') as f:
with sys.stdin as f:
    T = getInt(f)
    for t in xrange(1,T+1):
        n = getInt(f)
        if n == 0:
            s = 'INSOMNIA'
        else:
            s = 0
            d = set()
            while len(d) < 10:
                s += n
                d |= set(str(s))
        print 'Case #%d:' % t, s
        sys.stdout.flush()

