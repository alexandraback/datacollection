from __future__ import division
from decimal import Decimal

def solve (c,f,x,r,C,t):
    tx=(x-C)/r
    t1=(c-C)/r
    t2=x/(r+f)
    while (tx>t2+t1 and c<x):
        t=t+t1
        C=0
        r=r+f
        tx=(x-C)/r
        t1=(c-C)/r
        t2=x/(r+f)
    return t+tx
        
      
fin=open('../in','r') ; fout=open('../out','w')
cases=int(fin.readline().strip())
for case in range(1,cases+1):
    print case
    line=[Decimal(x) for x in fin.readline().strip().split(' ')]
    c=line[0]; f=line[1] ; x=line[2]
    fout.write("Case #"+str(case)+": "+str(solve(c,f,x,2,0,0))+"\n")