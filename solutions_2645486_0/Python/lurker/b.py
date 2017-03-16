
import sys
import os
import numpy as np

def sol(E, R, V):
    d = np.zeros((len(V) + 1, E + 1))
    for index, v in enumerate(V):
        i = index + 1
        for j in range(0, E + 1):
            d[i][j] = max( [ d[i-1][ max(0,min(E,j+k-R)) ] + V[index]*k for k in range(0, E - j + 1) ])
    return max(d[i,:])

rl = sys.stdin.readline
n = int(rl())
for i in range(n):
    e, r, vn = map(int, rl().split())
    v = map(int,rl().split())
    print "Case #%d: %d" %(i+1, sol(e,r,v))