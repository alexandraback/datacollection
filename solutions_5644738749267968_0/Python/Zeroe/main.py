import string
import sys
import math
import itertools
import operator
import cPickle
import collections

class Tee:
    def __init__(self, file):
        self.file = file
        
    def write(self, str):
        sys.stdout.write(str)
        self.file.write(str)

    def close(self):
        self.file.close()

def solveWar(A,B):
    B = collections.deque(B)
    p = 0
    
    for ai in A:
        if B[0] > ai:
            B.popleft()
        else:
            p += 1
            B.pop()
        
    return p

def solveDWar(A,B):
    B = collections.deque(B)
    p = 0
    
    for ai in reversed(A):
        if ai > B[-1]:
            p += 1
            B.pop()
    
    return p

def solve(A,B):
    A.sort(reverse=True)
    B.sort(reverse=True)
    return solveDWar(A, B), solveWar(A,B)
    

#name = "test"
name = "D-small-attempt0"
#name = "D-large"

fin = open(name+".in", "r")
fout = open(name+".out", "w")
fout = Tee(fout)

T = int(fin.readline())

for t in range(1,T+1):
    N = int(fin.readline())
    A = [float(x) for x in fin.readline().split()]
    B = [float(x) for x in fin.readline().split()]

    r0, r1 = solve(A,B)
    print >> fout, "Case #{}: {} {}".format(t, r0, r1)

