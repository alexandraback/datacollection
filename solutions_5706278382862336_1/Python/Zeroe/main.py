import string
import sys
import math
from itertools import *
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

def canBe(P,Q):
    if (P > Q):
        return False
    
    if (P == 0) or (Q == 0):
        return False
    
    nP = 2**40 * P
    if ((nP % Q) != 0):
        return False
    else:
        return True


def solve(P,Q):
    if not canBe(P,Q):
        return False
    
    r = 0
    while (P < Q):
        r += 1
        P = P*2

    return r


name = "test"
name = "A-small-attempt0"
name = "A-large"

fin = open(name+".in", "r")
fout = open(name+".out", "w")
fout = Tee(fout)

T = int(fin.readline())

for t in range(1,T+1):
    P,Q = [int(x) for x in fin.readline().split('/')]

    r = solve(P,Q);

    if (r is False):
        r = "impossible"

    print >> fout, "Case #{}: {}".format(t, r)

print "=== DONE ==="
