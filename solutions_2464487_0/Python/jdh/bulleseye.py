#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys,math

def getRet(r,t):
	a=(2.0*r-1.0)/4.0
	b=a*a+t/2.0
	c=math.sqrt(b)-a
	n=int(c)
	if n*n+(2.0*r-1.0)*n/2.0-t/2.0 <= 0:
	    if n>1:
		    return n
	if n>1:
		return n-1
	return 1

if __name__=="__main__":
    inFile = sys.argv[1]
    inFileObj = file(inFile)
    inLines = [line.strip() for line in inFileObj]
    nbTest = int(inLines[0])
    pos = 1
    for i in xrange(nbTest):
        #print inLines[pos]
        nbs = [int(x) for x in inLines[pos].split()]
        r = nbs[0]
        t = nbs[1]
        pos += 1
        s = 'Case #%d: ' % (i+1)
        s += str(getRet(r,t))
        print s
