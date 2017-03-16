import string
import sys
import math
from itertools import *
import operator
import cPickle
from collections import Counter
import copy

# Vladimir Burian

class Tee:
    def __init__(self, f):
        self.f = f
        
    def write(self, s):
        sys.stdout.write(s)
        self.f.write(s)

    def close(self):
        self.file.close()

def find_max(iterable):
    i,_ = max(enumerate(iterable), key=lambda x: x[1])
    return i

def read_int(fin):
    return int(fin.readline())

def read_ints(fin):
    return [int(x) for x in fin.readline().split()]

###############################################################################

def solve(D, Pi):
    # pancake cuts
    Ci = [0 for _ in Pi]
    Ti = list(Pi)
    
    tmin = max(Ti)
    
    while True:
        i = find_max(Ti)
        c = Ci[i] + 1
        
        if c >= Pi[i]:
            break
        
        t = (Pi[i] + c) / (c+1)
        
        if (t + c) <= (Ti[i] + Ci[i]):
            Ti[i] = t
            Ci[i] = c
        else:
            break
        
        tmin_new = max(Ti) + sum(Ci)
        tmin = min(tmin, tmin_new)
    
    return tmin

###############################################################################

name = "test"
name = "B-small-attempt0"
name = "B-large"

sys.setrecursionlimit(5000)

fin = open(name+".in", "r")
fout = open(name+".out", "w")
fout = Tee(fout)

T = int(fin.readline())

for t in range(1,T+1):
    D = read_int(fin)
    Pi = read_ints(fin)
    
    r = solve(D, Pi);
    print >> fout, "Case #{}: {}".format(t, r)

print "=== DONE ==="
