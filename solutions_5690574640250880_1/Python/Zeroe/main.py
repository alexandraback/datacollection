import string
import sys
import math
import itertools
import operator
import cPickle
from collections import Counter

class Tee:
    def __init__(self, file):
        self.file = file
        
    def write(self, str):
        sys.stdout.write(str)
        self.file.write(str)

    def close(self):
        self.file.close()
        
    
def subsolve(R,C,M,p):
    if C > R:
        n = min(R,M)
        if (n == R-1):
            n = R-2
        if (n == 0):
            return 0,0,1,p
        for x in xrange(n):
            p[R-x-1][C-1] = '*'
        M-=n
        C-=1
        if (C == 1) and (R-M > 1):
            return 0,0,1,p
        else:
            return R,C,M,p

    else:
        n = min(C,M)
        if (n == C-1):
            n = C-2
        if (n == 0):
            return 0,0,1,p
        for x in xrange(n):
            p[R-1][C-x-1] = '*'
        M-=n
        R-=1
        if (R == 1) and (C-M > 1):
            return 0,0,1,p
        else:
            return R,C,M,p
        
def solve(R,C,M):
    p = [['.' for _ in xrange(C)] for _ in xrange(R)]
    
    p[0][0] = 'c'
    
    while (M <> 0):
        R,C,M,p = subsolve(R, C, M, p)
        if (R == 0) or (C == 0):
            break
        
    if M == 0:
        for r in p:
            print >> fout, string.join(r, '')
    else:
        print >> fout, "Impossible"
    

#name = "test"
#name = "C-small-attempt1"
name = "C-large"

fin = open(name+".in", "r")
fout = open(name+".out", "w")
fout = Tee(fout)

T = int(fin.readline())

for t in range(1,T+1):
    R,C,M = [int(x) for x in fin.readline().split()]

    print >> fout, "Case #{}:".format(t)
    solve(R,C,M)
    
