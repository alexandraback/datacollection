numcases=int(raw_input())

for i in xrange(0,numcases):
	numTyped,passSize=map(int,raw_input().split())
	pCorr=map(float,raw_input().split())

	pItoN=[pCorr[0]]
	#calc prob that i...n is wrong
	for k in pCorr[1:]:
		pItoN.append(pItoN[-1]*k)

	vals=[]
	for numBkSpaces in xrange(0,numTyped):
		expr=numBkSpaces+(passSize-numTyped+numBkSpaces+1)+(1-pItoN[-1-numBkSpaces])*(passSize+1)
		vals.append(expr)

	print "Case #%d: %f"%(i+1,min(min(vals),passSize+2))
