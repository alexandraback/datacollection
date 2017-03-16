#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys,math

def getNb(T,X,Y):
    n=X+Y
    k=n/2
    if T <= k*(2*k-1):
        return "0.0"
    elif T >= (k+1)*(2*k+1):
        return "1.0"
    D=T-k*(2*k-1)
    if X == 0:
        return "0.0"
    if D < Y:
        return "0.0"
    nb=0
    CDi=1
    for i in xrange(Y+1):
        if i > 0:
            CDi=CDi*(D-i+1)/i
        nb+=CDi
    #print nb,D
    return str(1-nb*0.5**D)

if __name__=="__main__":
    inFile = sys.argv[1]
    inFileObj = file(inFile)
    inLines = [line.strip() for line in inFileObj]
    nbTest = int(inLines[0])
    pos = 1
    for i in xrange(nbTest):
        #print inLines[pos]
        TXY = [int(x) for x in inLines[pos].split()]
        T = TXY[0]
        X = TXY[1]
        if X < 0:
            X = -X
        Y = TXY[2]
        pos += 1
        s = 'Case #%d: ' % (i+1)
        s += getNb(T,X,Y)
        print s
