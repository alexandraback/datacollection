#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys,math
import Queue

AA = 750
M = [['' for x in xrange(-AA,AA)] for y in xrange(-AA,AA)]

def init():
    V = [[0 for x in xrange(-AA,AA)] for y in xrange(-AA,AA)]
    q=Queue.Queue()
    q.put((0,0))
    while not q.empty():
        a=q.get()
        X=a[0]
        Y=a[1]
        if V[X][Y] == 1:
            continue
        V[X][Y]=1
        s=M[X][Y]
        l=len(s)+1
        if Y+l <AA and M[X][Y+l]=='':
            M[X][Y+l]=s+'N'
            q.put((X,Y+l))
        if Y-l >-AA and M[X][Y-l]=='':
            M[X][Y-l]=s+'S'
            q.put((X,Y-l))
        if X+l <AA and M[X+l][Y]=='':
            M[X+l][Y]=s+'E'
            q.put((X+l,Y))
        if X-l >-AA and M[X-l][Y]=='':
            M[X-l][Y]=s+'W'
            q.put((X-l,Y))

def getStr(X,Y):
    return M[X][Y]

if __name__=="__main__":
    init()
    inFile = sys.argv[1]
    inFileObj = file(inFile)
    inLines = [line.strip() for line in inFileObj]
    nbTest = int(inLines[0])
    pos = 1
    for i in xrange(nbTest):
        #print inLines[pos]
        N = [int(x) for x in inLines[pos].split()]
        X = N[0]
        Y = N[1]
        pos += 1
        s = 'Case #%d: ' % (i+1)
        s += getStr(X,Y)
        print s
