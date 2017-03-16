#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

def cal(i,A,B):
    n = len(str(i))
    j = i
    nbSet = set()
    for pos in xrange(n-1):
        a = j/10
        b = j%10
        j = b*(10**(n-1)) + a
        if i < j and j <= B:
            nbSet.add(j)
    return len(nbSet)

def getRet(nbs):
    A = nbs[0]
    B = nbs[1]
    ret = 0
    for i in xrange(A,B):
        ret += cal(i,A,B)
    return ret

if __name__=="__main__":
    inFile = sys.argv[1]
    inFileObj = file(inFile)
    inLines = [line.strip() for line in inFileObj]
    nbTest = int(inLines[0])
    for i in xrange(nbTest):
        nbs = [int(x) for x in inLines[i+1].split()]
        s = 'Case #%d: ' % (i+1)
        s += str(getRet(nbs))
        print s
