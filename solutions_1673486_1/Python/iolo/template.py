#!/usr/bin/python

import sys

def getExpected(typed,total,fprobs,accumprob):
	if typed==0:
		prob=1.0
	else:
		prob=accumprob*fprobs[typed-1]
	ksOk=prob*(total-typed+1)
	ksKo=(1.0-prob)*((total-typed)+2+total)	
	return (prob,ksOk+ksKo)

def processCase(case):
	# *** BEGIN CODE PROCESSING CASE ***

	typed=int(case.split()[0])
	total=int(case.split()[1])

	probs=sys.stdin.readline()

	fprobs=[]
	for prob in probs.split():
		fprobs.append(float(prob))
	
	expecteds=total+2
	accum=1.0
	cand=1.0
	for deletes in reversed(xrange(typed+1)):
		(accum,cand)=getExpected(typed-deletes,total,fprobs,accum)
		cand=cand+deletes
		if cand<expecteds:
			expecteds=cand

	# *** END CODE PROCESSING CASE ***
	return expecteds 

def readCase(case):

	# *** BEGIN CODE READING CASE ***
	caseInput=sys.stdin.readline()
		
	# *** END CODE READING CASE ***

	solution=processCase(caseInput)
	print "Case #"+str(case)+": "+str(solution)

cases=int(sys.stdin.readline())

for case in range(cases):
	readCase(case+1)

