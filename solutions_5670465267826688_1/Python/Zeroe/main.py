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

def find(iterable, element):
    for i,e in enumerate(iterable):
        if e == element:
            return i
    return None

def read_int(fin):
    return int(fin.readline())

def read_ints(fin):
    return [int(x) for x in fin.readline().split()]

###############################################################################

Q1 = 0
Qi = 1
Qj = 2
Qk = 3

Qm1 = 4
Qmi = 5
Qmj = 6
Qmk = 7

SYMBOLS = {'i':Qi, 'j':Qj, 'k':Qk}

MUL = [[ 0,1,2,3, 4,5,6,7 ],
       [ 1,4,3,6, 5,0,7,2 ],
       [ 2,7,4,1, 6,3,0,5 ],
       [ 3,2,5,4, 7,6,1,0 ],
       
       [ 4,5,6,7, 0,1,2,3 ],
       [ 5,0,7,2, 1,4,3,6 ],
       [ 6,3,0,5, 2,7,4,1 ],
       [ 7,6,1,0, 3,2,5,4 ]]  


def solve(L,X,S):
    S = [SYMBOLS[x] for x in S]
    
    if X > 12:
        X = 8 + (X % 4)
    
    S = S * X
    L = L * X
    
    assert L == len(S)
    
    # check total product
    P = reduce(lambda x,y: MUL[x][y], S, Q1)
    
    if (P <> Qm1):
        return False
    
    # check left product
    P = Q1
    i1 = None
    
    for i in xrange(L):
        q = S[i]
        P = MUL[P][q]
        
        if P == Qi:
            i1 = i
            break
    
    if i1 is None:
        return False
    
    # check center product
    P = Q1
    i2 = None
    
    for i in xrange(i1+1, L):
        q = S[i]
        P = MUL[P][q]
        
        if P == Qj:
            i2 = i
            break
    
    if i2 is None:
        return False
    
    return True

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
    L,X = read_ints(fin)
    S = fin.readline().strip()
    
    r = solve(L,X,S);
    r = 'Yes' if r else 'No'
    
    print >> fout, "Case #{}: {}".format(t, r)

print "=== DONE ==="
