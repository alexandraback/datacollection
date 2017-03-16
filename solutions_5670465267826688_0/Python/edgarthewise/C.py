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

symIx = {'1': 0,'i':1,'j':2,'k':3,'-1':4}

mul = array([
[0,1,2,3],
[1,4,3,6],
[2,7,4,1],
[3,2,5,4]], dtype=int8)
mul = hstack([mul, bitwise_xor(mul, 4)])
mul = vstack([mul, bitwise_xor(mul, 4)])

order = 4

T = getInt()

for caseNo in xrange(1,T+1):
	L, X = getInts()
	S = array([ symIx[i] for i in getWords()[0] ], dtype=int8)
	
	totalProd = symIx['1']; leftCumProd = []
	for i in xrange(L):
		leftCumProd.append(totalProd)
		totalProd = mul[totalProd, S[i]]
	leftCumProd=array(leftCumProd,dtype=int8)
	totalProd2 = symIx['1']; rightCumProd = []
	for i in xrange(L-1, -1, -1):
		rightCumProd.append(totalProd2)
		totalProd2 = mul[S[i], totalProd2]
	rightCumProd=array(rightCumProd,dtype=int8)
	assert totalProd == totalProd2
	
	totalProdToX = symIx['1']
	for pwr in xrange(X%order):
		totalProdToX = mul[totalProdToX, totalProd]
	if totalProdToX != symIx['-1']:
		#print "prod not -1"
		print "Case #%d: NO"%caseNo
		continue
	
	firstIxForI = None
	leftProds = leftCumProd.copy()
	for cycle in range(min(order, X)):
		if (leftProds == symIx['i']).any():
			firstIxForI = cycle*L + where(leftProds == symIx['i'])[0][0]
			break
		leftProds = mul[totalProd, leftProds]
	if firstIxForI is None:
		#print "no subprod i"
		print "Case #%d: NO"%caseNo
		continue

	lastIxForK = None
	rightProds = rightCumProd.copy()
	for cycle in range(min(order, X)):
		if (rightProds == symIx['k']).any():
			lastIxForK = L*X - cycle*L - where(rightProds == symIx['k'])[0][0]
			break
		rightProds = mul[rightProds, totalProd]
	if lastIxForK is None:
		#print "no subprod k"
		print "Case #%d: NO"%caseNo
		continue

	if firstIxForI < lastIxForK:
		print "Case #%d: YES"%caseNo
	else:
		#print "not enough room"
		print "Case #%d: NO"%caseNo
