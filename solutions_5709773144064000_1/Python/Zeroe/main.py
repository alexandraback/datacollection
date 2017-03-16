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
        
    
def getGain(F, nF):
    return 2 + nF*F
        
def solve(C,F,X):
    t = 0
    nF = 0
    
    while True:
        g = getGain(F, nF)
        
        t0 = X / g
        t1 = C / g
        
        if (t0 <= t1):
            return t + t0
        
        tf = t1
        t1 += X / getGain(F, nF+1)
        
        if (t0 <= t1):
            return t + t0
        
        nF += 1
        t += tf
    

#name = "test"
#name = "B-small-attempt0"
name = "B-large"

fin = open(name+".in", "r")
fout = open(name+".out", "w")
fout = Tee(fout)

T = int(fin.readline())

for t in range(1,T+1):
    C,F,X = [float(x) for x in fin.readline().split()]

    r = solve(C,F,X)
    print >> fout, "Case #{}: {:.7f}".format(t, r)

