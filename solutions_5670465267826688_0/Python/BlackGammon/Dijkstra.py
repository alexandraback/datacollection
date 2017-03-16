from sys import *
import numpy as np

def readval(fi, ty): return ty(fi.readline())
def readtab(fi, ty): return tuple(map(ty, fi.readline().split()))

M = [[1,2,3],[4,3,6],[7,4,1],[2,5,4]]
    
fi = open(argv[1], 'r')
T = readval(fi, int)
for k in range(T):
    l,f = readtab(fi, int)
    s0 = readval(fi,str)
    s = [ord(s0[i%l]) - ord('i') for i in range(l*f)]
    iFound = False
    jFound = False
    m = 0
    for i in range(len(s)):
        m = (M[m % 4][s[i]] + 4 * (m / 4)) % 8
        if m == 1:
            iFound = True
        if iFound and m == 3:
            jFound = True
    if jFound and m == 4:
        sol = "YES"
    else:
        sol = "NO"
    
    print "Case #"+str(k+1)+": "+sol
