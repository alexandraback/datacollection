from sys import stdin, stdout, exit
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
	def e(r):
		print "Case #%d: %s"%(caseNo, ("GABRIEL" if r else "RICHARD"))

	X, R, C = getInts()
	if R<C:
		R,C=C,R

	# Worked out on paper, case by case.
	if ((R*C)%X != 0):
		e(False)
	elif X<=2:
		e(True)
	elif X==3:
		e(C>=2)
	elif X==4:
		e(R>=4 and C>=3)
	elif X==5:
		e( (R>=5 and C>=4) or (R>=10 and C>=3) )
	elif X==6:
		e(R>=6 and C>=4)
	else: #X>=7 
		e(False)
