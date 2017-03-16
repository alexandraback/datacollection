#!/usr/bin/python

import sys
fin=sys.stdin
T=int(fin.readline())

def get2(x):
    a=0
    while 2**a<=x:
        a+=1
    return a-1

def solve(a,b,k):
    if a>b:
        return solve(b,a,k)
    elif k>=b:#b>=a
        return a*b
    elif a==2**get2(a) and b==2**get2(b):
        pass
    elif True:#b>=a>k
        return 0

for i in range(T):
    [a,b,k]=[int(x) for x in fin.readline().split()]
    s=0
    #print(a,b,k,file=sys.stderr)
    s=len(list(filter(lambda x:x[0]&x[1]<k,[(x,y) for x in range(a) for y in range(b)])))
    print("Case #%d: %d"%(i+1,s))

