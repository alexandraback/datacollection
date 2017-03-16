#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

def getRet(nbs):
    TotNb = nbs[0]
    NbSup = nbs[1]
    P = nbs[2]
    totals = nbs[3:]
    ret = 0
    sup = 0
    disc = 0
    for i in totals:
        if i >= 3*P:
            ret +=1
        elif P >= 1 and i >= 3*P - 2:
            ret += 1
        elif P >= 2 and i >= 3*P - 4 and sup < NbSup:
            ret += 1
            sup += 1
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
