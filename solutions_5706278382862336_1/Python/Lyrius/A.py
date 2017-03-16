# -*- coding: utf-8 -*-
"""
Created on Sun May 11 11:01:35 2014

@author: matthieu
"""

import numpy as np
def ispuissance2(v):
    while(v>1):
        if v%2==1:
            return False
        v/=2
    return True

def simplification(u,v):
    for i in range(1,int(np.sqrt(u))):
        if(u%i==0):
            if(v%i==0 and i!=1):
                return simplification(u/i,v/i)
            if(v%(u/i))==0:
                return simplification(u/(u/i),v/(u/i))
    return u,v
    
inp  = open("input","r")
out = open("output","w")

T = int(inp.readline())
for case in range(T):
    out.write("Case #"+str(case+1)+": ")
    line = inp.readline()
    line = line.split("/")
    P = int(line[0])
    Q = int(line[1])
    P,Q = simplification(P,Q)
    if not ispuissance2(Q):
        out.write("impossible\n")
        continue
    while(P!=1):
        P-=P%2
        P/=2
        Q/=2
    out.write(str(int(round(np.log2(Q),0))))
    out.write("\n")


out.close()
    





