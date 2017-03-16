#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys,math

def getNb(n,A,nbs):
    #print n,A,nbs
    if len(nbs) == 0:
        return n
    if A > nbs[0]:
        if len(nbs) == 1:
            return n
        A+=nbs[0]
        return getNb(n,A,nbs[1:])
    else:
        if len(nbs) == 1:
            return n+1
        N1=getNb(n+1,A,nbs[1:])
        if A <= 1:
            return N1
        ret=n+1
        A1=2*A-1
        while A1 <= nbs[0]:
            ret+=1
            A1=2*A1-1
        N2=getNb(ret,A1,nbs)
        if N1 <= N2:
            return N1
        else:
            return N2

if __name__=="__main__":
    inFile = sys.argv[1]
    inFileObj = file(inFile)
    inLines = [line.strip() for line in inFileObj]
    nbTest = int(inLines[0])
    pos = 1
    for i in xrange(nbTest):
        #print inLines[pos]
        AN = [int(x) for x in inLines[pos].split()]
        A = AN[0]
        N = AN[1]
        pos += 1
        nbs = [int(x) for x in inLines[pos].split()]
        nbs.sort()
        #print A,N,nbs
        pos += 1
        s = 'Case #%d: ' % (i+1)
        s += str(getNb(0,A,nbs))
        print s
