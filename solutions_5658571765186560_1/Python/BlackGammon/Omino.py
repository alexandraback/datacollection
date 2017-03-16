from sys import *
import numpy as np

def readval(fi, ty): return ty(fi.readline())
def readtab(fi, ty): return tuple(map(ty, fi.readline().split()))
    
def richard(X, R, C):
    if (R * C) % X != 0 or X > max(R, C):
        return True
    if C > 2:
        return False
    if C == 1:
        return X >= 3
    if C == 2:
        if R <= 3:
            return False
        else:
            return X >= R
#    if R <= 4:
#        return False
#    return X >=
    

fi = open(argv[1], 'r')
T = readval(fi, int)
for k in range(T):
    X, R, C = readtab(fi, int)
    if richard(X, max(R, C), min(R, C)):
        sol = "RICHARD"
    else:
        sol = "GABRIEL"
    print "Case #"+str(k+1)+": "+sol
