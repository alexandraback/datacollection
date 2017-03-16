import string
import sys
import math
from itertools import *
import operator
import cPickle
from collections import Counter
import copy

class Tee:
    def __init__(self, file):
        self.file = file
        
    def write(self, str):
        sys.stdout.write(str)
        self.file.write(str)

    def close(self):
        self.file.close()

class Cache:
    def __init__(self):
        self.cache = dict()
        
    def has(self, *args):
        return (args in self.cache)
    
    def set(self, v, *args):
        self.cache[args] = v
    
    def get(self, *args):
        return self.cache[args]

def functionCallCache(f):
    cache = dict()
    def fce(*args):
        t = tuple(args)
        if (t in cache):
            return cache[t]
        else:
            r = f(*args)
            cache[t] = r
            return r
    return fce


def read_int(fin):
    return int(fin.readline())

def read_ints(fin):
    return [int(x) for x in fin.readline().split()]

###############################################################################

def solve(fin):
    Smax, Ni = fin.readline().split()
    
    Smax = int(Smax)
    Ni = [int(x) for x in Ni]
    
    N = 0
    C = 0
    
    for k,Si in enumerate(Ni):
        if (k > C) and (Si <> 0):
            N += k - C
            C += k - C
        C += Si
    
    return N

###############################################################################

name = "test"
name = "A-small-attempt0"
#name = "B-large-practice"

sys.setrecursionlimit(5000)

fin = open(name+".in", "r")
fout = open(name+".out", "w")
fout = Tee(fout)

T = int(fin.readline())

for t in range(1,T+1):
    r = solve(fin);
    print >> fout, "Case #{}: {}".format(t, r)

print "=== DONE ==="
