import sys
import numpy as np

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
        S = getLine(f)
        N = len(S)
        X = np.array([ ord(c) for c in S])
        maxX = np.maximum.accumulate(X)
        wX = np.concatenate([ X[X==maxX][::-1], X[X!=maxX] ])
        word = ''.join([chr(c) for c in wX])
        print 'Case #%d:' % t, word
        sys.stdout.flush()

