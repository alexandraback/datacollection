#!/usr/bin/env python
import sys
import numpy as np

infile=open(sys.argv[1],'r')

NumCases=int(infile.readline())

for iCase in xrange(NumCases):
    a,b=[int(i) for i in infile.readline().split()]

    nleft=b-a

    probs=[1-float(i) for i in infile.readline().split()]

    best=np.inf

    #backspaces first
    totalProb=1.0
    for ii,p in enumerate(probs):
        nStrokes=(2*(a-ii)+nleft+1.0)*(totalProb)+(
            2*(a-ii)+nleft+b+2.0)*(1-totalProb)
        #print 'backspace to',ii,nStrokes,totalProb
        if nStrokes<best: best=nStrokes
        totalProb=(1-p)*totalProb


    #Enter right away
    nStrokes=1.0*(2+b)
    if nStrokes<best: best=nStrokes
    #print 'enter',nStrokes,best

    #keep going
    nStrokes=totalProb*(nleft+1.0)+(1.0-totalProb)*(nleft+2+b)
    if nStrokes<best: best=nStrokes
    #print 'finish',nStrokes,best


    print 'Case #'+str(iCase+1)+': %1.6f'%best

