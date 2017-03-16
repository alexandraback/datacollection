from __future__ import division
import sys
import os
T=int(raw_input())
for i in range(T):
    ans=0.0
    C,F,X=raw_input().split(' ')
    C=float(C)
    F=float(F)
    X=float(X)
    base=X/2
    k=1
    s_last=2
    s1=C/s_last+X/(F+s_last)
    while (s1<base):
        base=s1
        s_last=s_last+F
        s1=s1-X/s_last+X/(s_last+F)+C/(s_last)
    
    ans=base
    
    print "Case #%d: %.7lf"%(i+1,ans)

