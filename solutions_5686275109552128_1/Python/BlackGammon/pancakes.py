from sys import *
import numpy as np

def readval(fi, ty): return ty(fi.readline())
def readtab(fi, ty): return tuple(map(ty, fi.readline().split()))
    
fi = open(argv[1], 'r')
T = readval(fi, int)
for k in range(T):
    D = readval(fi, int)
    P = map(int, fi.readline().split())
    v = max(P)
    m = v
    for c in range(2, v):
        m = min(m, sum((P[i] - 1)/c for i in range(len(P))) + c)
    print "Case #"+str(k+1)+": "+str(m)
