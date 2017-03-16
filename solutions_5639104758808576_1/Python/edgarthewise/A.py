from sys import stdin, stdout
from numpy import *

def getWords(f):
    return f.readline().strip().split()

with open('Downloads/A-large.in') as F:
    with open('A-large.out','wt') as O:
        T = int(getWords(F)[0])
        for caseNo in xrange(1,T+1):
            S_max, S_raw = getWords(F)
            maxS = int(S_max)
            atLevelCount = array([int(c) for c in S_raw])
            assert len(atLevelCount)==maxS+1
    
            underLevelCount = concatenate([[0],cumsum(atLevelCount[:-1])])
            res = (arange(maxS+1) - underLevelCount).max()
            print >>O, "Case #%d: %d"%(caseNo,res)
