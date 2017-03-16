import sys,math
from decimal import *

f = open(sys.argv[1],'r')
n = int(next(f))

def answer(a,E,R):
    m = max(a)
    return R*sum(a)+(E-R)*m
    

for i in range(n):
    E,R,N = list(map(int,next(f).split(" ")))
    R = min(E,R)
    a = list(map(int,next(f).split(" ")))
    print("Case #%d: %s"%(i+1,answer(a,E,R)))
