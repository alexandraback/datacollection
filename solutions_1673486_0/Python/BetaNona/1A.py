#!/usr/bin/env python

import sys

import string

infile=open(sys.argv[1])

def solve(A,B,ps):
    assert len(ps)==A
    
    corProb=[1]
    for p in ps:
        corProb.append(corProb[-1]*p*2)
    #print corProb
    
    ans=B+2
    for n in range(len(corProb)):
        if n==0:
            ex=(1+B+1)
        else:
            exok=corProb[n]*((A-n)+(B-n)+1)/(2**n)
            exng=((2**n)-corProb[n])*((A-n)+(B-n)+1+B+1)/(2**n)
            ex=exok+exng
            #print A,B,n,exok,exng,ex
        ans=min(ans,ex)
    return ans

for n,line in enumerate(infile):
    if n==0:
        T=int(line)
        continue
    elif n%2==1:
        A,B=line.split()
        A=int(A)
        B=int(B)
    else:
        ls=[float(x) for x in line.split()]
        
        ans=solve(A,B,ls)
        print "Case #%d: %f" % (n/2,ans)

