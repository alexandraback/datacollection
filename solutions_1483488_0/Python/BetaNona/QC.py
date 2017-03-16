#!/usr/bin/env python

import sys

import string

infile=open(sys.argv[1])

def numrec(m,A):
    ns=set()
    s=str(m)
    for i in range(1,len(s)):
        rot=int(s[i:]+s[0:i])
        if s[i]!="0" and A <= rot < m:
            ns.add(rot)
    #print m,ns
    return len(ns)

def solve(A,B):
    total=0
    for m in range(A,B+1):
        total+=numrec(m,A)
    return total

for n,line in enumerate(infile):
    if n==0:
        T=int(line)
        continue
        
    ls=[int(x) for x in line.split()]
    ans=solve(ls[0],ls[1])

    print "Case #%d: %d" % (n,ans)

