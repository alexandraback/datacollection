import sys

from math import *
from itertools import *
from collections import defaultdict

def lg(a) :
    sys.stderr.write(str(a)+"\n")

def sol(c,f,x) :
    fbtM = 0.0 # factory buy time, fbt[0] is zeroth.
    perfM = 2.0
    solM = 1e9
    while True : # !
	solC = fbtM+x/perfM
	tf = c/perfM
	fbtC = tf+fbtM
	perfC = perfM+f
	if solC>solM :
	    return solM
	solM = solC
	perfM = perfC
	fbtM = fbtC


t = int(sys.stdin.readline())
for testNr in range(1,t+1) :
    c,f,x = map(float,sys.stdin.readline().split())
    print "Case #%d:" % testNr ,
    print sol(c,f,x)
