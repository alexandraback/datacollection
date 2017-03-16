import string
import sys
import math
from itertools import *
import operator
import cPickle
from collections import Counter
from copy import copy, deepcopy

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

def diff(l):
    return [p[1] - p[0] for p in izip(l[:-1], l[1:])]

def binary_search(pmin, pmax, v, fce):
    assert (pmax >= pmin)
    assert(fce(pmin) <= v)
    assert(fce(pmax) >= v)
    
    while (pmin+1 < pmax):
        p = long(pmin + pmax + 1) / 2
        vp = fce(p)
        
        if (vp >= v):
            pmax = p
        else:
            pmin = p

    if (fce(pmin) >= v):
        return pmin
    if (fce(pmax) >= v):
        return pmax
    
    assert False

###############################################################################

def clean_map(bffmap, Fs):
    bffpred = Counter(Fs)
    nonebff = set(xrange(len(Fs))) - set(Fs)

    for nbff in nonebff:
        id = nbff
        
        while bffpred[id] == 0:
            bff = bffmap[id]
            del bffmap[id]
            
            bffpred[bff] -= 1
            id = bff

    assert(set(bffmap.keys()) == set(bffmap.values()))

def biggest_ring(bffmap):
    visited = set()
    ids = bffmap.keys()
    
    maxcnt = 0
    
    for id in ids:
        cnt = 0
        
        while id not in visited:
            cnt += 1
            visited.add(id)
            id = bffmap[id]

        maxcnt = max(maxcnt, cnt)

    return maxcnt

def extract_reci(bffmap):
    visited = set()
    ids = bffmap.keys()

    for id1 in ids:
        if id1 in visited:
            continue
        
        id2 = bffmap[id1]
        
        if id2 in visited:
            continue
        
        if bffmap[id2] == id1:
            visited.add(id1)
            visited.add(id2)

    return visited

def count_one_way(Fs, bffmap, reci):
    nonebff = set(xrange(len(Fs))) - set(Fs)
    oneway = Counter()
    
    for id in nonebff:
        visited = set()

        while id not in visited:
            if id in reci:
                oneway[id] = max(oneway[id], len(visited))
                break

            visited.add(id)
            id = bffmap[id]

    return sum(oneway.values())

def solve(fin):
    N = read_int(fin)
    Fs = read_ints(fin)
    Fs = [i-1 for i in Fs]
    
    bffmap = {k:v for k,v in enumerate(Fs)}
    
    bffmapsimple = deepcopy(bffmap)
    clean_map(bffmapsimple, Fs)
    
    r1 = biggest_ring(bffmapsimple)

    reci = extract_reci(bffmapsimple)
    r2 = count_one_way(Fs, bffmap, reci) + len(reci)

    return max(r1, r2)

###############################################################################

name = "test"
name = "C-small-attempt0"
name = "C-large"

sys.setrecursionlimit(5000)

fin = open(name+".in", "r")
fout = open(name+".out", "w")
fout = Tee(fout)

T = int(fin.readline())

for t in range(1,T+1):
    r = solve(fin);
    print >> fout, "Case #{}: {}".format(t, r)
    sys.stdout.flush()

print "=== DONE ==="
