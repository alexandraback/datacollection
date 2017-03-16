#!/usr/bin/env python
import math
import sys
def MaxPossible(T,S,p):
    # All situations
    # 3*x
    # (x,x,x) or (x-1,x,x+1)
    # 3*x+1
    # (x,x,x+1) or (x-1,x+1,x+1)
    # 3*x+2
    # (x,x+1,x+1) or (x,x,x+2)
    n=0
    m=0 #possible improvment
    for t in T:
        x=t/3#x>=0
        rem=t%3
        if rem ==0:
            if x>=p:
                n+=1
            elif (x-1>=0) and (x+1==p):
                m+=1
        elif rem==1:
            if x+1>=p:
                n+=1
        else:
            if x+1>=p:
                n+=1
            elif (x+2==p):
                m+=1
    return n+min(S,m)
    
fname1=sys.argv[1]
fname2=fname1+".out"
f1=open(fname1)
f2=open(fname2,"w")
f1=open(fname1)
f2=open(fname2,"w")

f1.readline()
i=1
for line in f1:
    input=[int(x) for x in line.split()]
    S=input[1]
    p=input[2]
    T=input[3:]
    output=MaxPossible(T,S,p)
    f2.write("Case #"+str(i)+": "+
             str(output)+"\n")
    i+=1
f1.close()
f2.close()
