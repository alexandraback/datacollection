import sys
import numpy as np

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
        N = getInt(f)
        res = np.flatnonzero(np.bincount(
            np.asarray([ getInts(f) for i in xrange(2*N-1) ]).flatten())%2)
        assert(len(res)==N)
        print 'Case #%d:' % t, ' '.join([str(i) for i in res])
        sys.stdout.flush()

