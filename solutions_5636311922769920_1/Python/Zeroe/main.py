# Vladimir Burian, 2016 (vladaburian@gmail.com)

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

def read_int(fin):
    return int(fin.readline())

def read_ints(fin):
    return [int(x) for x in fin.readline().split()]

###############################################################################

def solve(fin):
    K, C, S = read_ints(fin)

    if (C*S < K):
        return "IMPOSSIBLE"

    r = []

    for i in xrange(0, K, C):
        p_ref = 0
        p = i

        for j in (min(x, K-1) for x in xrange(i+1, i+C)):
            p_ref = K*p
            p = p_ref + j

        r.append(p+1)

    assert(all(1 <= x <= K**C for x in r))

    r = " ".join(str(x) for x in r)
    return r

###############################################################################

name = "test"
name = "D-small-attempt1"
name = "D-large"

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

