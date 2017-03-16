#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

def getRet(A,B,P):
    ret = 0.0
    #print A,B,P
    Q = []
    Q.append(1.0)
    for i in xrange(A):
        Q.append(P[i] * Q[i])
    #print Q
    for i in xrange(A):
        j = A - i
        N = (B-i+1 + j) + (1-Q[i]) * (B+1)
        #print (B-i+1 + j),(1-Q[i]),(B+1),N
        if ret == 0 or ret > N:
            ret = N
    N = 2.0 + B
    if ret == 0 or ret > N:
        ret = N
    N = (B-A+1) + (1-Q[A])*(B+1)
    if ret == 0 or ret > N:
        ret = N
    return '%.6f' % ret

if __name__=="__main__":
    inFile = sys.argv[1]
    inFileObj = file(inFile)
    inLines = [line.strip() for line in inFileObj]
    nbTest = int(inLines[0])
    for i in xrange(nbTest):
        A,B = [int(x) for x in inLines[2*i+1].split()]
        P = [float(x) for x in inLines[2*i+2].split()]
        s = 'Case #%d: ' % (i+1)
        s += str(getRet(A,B,P))
        print s
