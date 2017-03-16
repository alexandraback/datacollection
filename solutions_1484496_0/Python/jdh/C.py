#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import itertools
def findsubsets(S,m):
    return set(itertools.combinations(S, m))

def getRet(n,l):
    sol=dict()
    ls=len(l)
    for m in xrange(ls):
        for s in findsubsets(range(ls),m):
            a=0
            for ta in s:
                a+=l[ta]
            if a in sol:
                for b in sol[a]:
                    print l[b],
                print
                for b in s:
                    print l[b],
                print
                return
            else:
                sol[a]=s
    print 'Impossible'
    
if __name__=="__main__":
    inFile = sys.argv[1]
    inFileObj = file(inFile)
    inLines = [line.strip() for line in inFileObj]
    nbTest = int(inLines[0])
    for i in xrange(nbTest):
        l=[int(x) for x in inLines[i+1].split()]
        n=l[0]
        s = 'Case #%d: ' % (i+1)
        print s
        getRet(n,l[1:])
