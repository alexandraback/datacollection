#!/usr/bin/env python

import sys

import string

infile=open(sys.argv[1])

def solve(N,S,p,ts):
    assert len(ts)==N
    pman=0
    pman_ifsup=0
    for t in ts:
        if t>=29:
            nonsup=10;sup=10
        elif t==0:
            nonsup=0;sup=0
        elif t%3 == 0:
            nonsup=t//3;sup=t//3+1
        elif t%3 == 1:
            nonsup=t//3+1;sup=t//3+1
        elif t%3 == 2:
            nonsup=t//3+1;sup=t//3+2
        else:
            assert False
        if nonsup>=p:
            pman+=1
        elif sup>=p:
            pman_ifsup+=1
    if pman_ifsup>=S:
        return pman+S
    else:
        return pman+pman_ifsup

for n,line in enumerate(infile):
    if n==0:
        T=int(line)
        continue
        
    ls=[int(x) for x in line.split()]
    ans=solve(ls[0],ls[1],ls[2],ls[3:])

    print "Case #%d: %d" % (n,ans)

