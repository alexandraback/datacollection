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


###############################################################################

def solve(fin):
    S = fin.readline().strip()
    S += '+'
    
    r = sum(S[i] <> S[i+1] for i in xrange(len(S)-1))
    
    return r

###############################################################################

name = "test"
name = "B-small-attempt0"
#name = "A-large-practice"

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

