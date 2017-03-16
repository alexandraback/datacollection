from sys import stdin, stdout
from numpy import *

def getWords():
    return stdin.readline().strip().split()

def getInts():
    return array([int(i) for i in getWords()], dtype=int)

def getInt():
	i = getInts()
	assert len(i)==1
	return i

T = getInt()
for caseNo in xrange(1,T+1):
	D = getInt()
	P = getInts()
	
	best = P.max()
	
	for minutesToEat in range(1, P.max()):
		minutesToServe = ((P-1)//minutesToEat).sum()
		best = min(best, minutesToEat + minutesToServe)
	
	print "Case #%d: %d"%(caseNo, best)
