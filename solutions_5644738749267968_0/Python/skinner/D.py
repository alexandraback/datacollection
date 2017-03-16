import sys

from math import *
from itertools import *
from collections import defaultdict

def lg(a) :
    sys.stderr.write(str(a)+"\n")

def toBV(x,y) :
    xx = [ (p,0) for p in x ]
    yy = [ (p,1) for p in y ]
    zz = sorted(xx+yy)
    return [ pp[1] for pp in zz ]

def isSortedReverse(l) :
    return all(l[i] >= l[i+1] for i in xrange(len(l)-1))

def maxKen(bv) :
    p = len(bv)-1
    while p>=0 :
	if bv[p]==1 :
	    return p
	p -= 1
    assert False

def minNaomi(bv) :
    p = 0
    while p<len(bv) :
	if bv[p]==0 :
	    return p
	p += 1
    assert False

def minKen(bv) :
    p = 0
    while p<len(bv) :
	if bv[p]==1 :
	    return p
	p += 1
    assert False

def nextKen(bv,p) :
    while p<len(bv) :
	if bv[p]==1 :
	    return p
	p += 1
    return -1

def dw(bv) :
    wins = 0
    while len(bv)>0 :
	if bv[0]==0 :
	    mk = maxKen(bv)
	    bv = bv[1:mk]+bv[mk+1:]
	else :
	    mn = minNaomi(bv)
	    bv = bv[1:mn]+bv[mn+1:]
	    wins += 1
    return wins

def w(bv) :
    wins = 0
    while len(bv)>0 :
	mn = minNaomi(bv)
	del bv[mn]
	nk = nextKen(bv,mn)
	if nk==-1 :
	    nk = minKen(bv)
	    assert nk<mn
	    wins += 1
	del bv[nk]
    return wins

def sol(x,y) :
    bv = toBV(x,y)
    return "%d %d" % (dw(bv),w(bv))

t = int(sys.stdin.readline())
for testNr in range(1,t+1) :
    n = int(sys.stdin.readline())
    x = map(float,sys.stdin.readline().split())
    y = map(float,sys.stdin.readline().split())
    assert len(x)==len(y)==n
    print "Case #%d:" % testNr ,
    print sol(x,y)
