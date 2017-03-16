INPUT_FILE = "C-small-attempt1.in"
OUTPUT_FILE = "C-small-attempt1.out"

import math

global result
global fairAndSquare


def IsPalindrom(x):
	if str(x) == str(x)[::-1]:
		return True
	else:
		return False


		
def FindAllFair():
	global fairAndSquare
	i = 0
	fairAndSquare = [1,2,3,11,22]
	baseNumbers = ["1","2"]
	while True:
		#print baseNumbers
		newbaseNumbers = []
		for baseNumber in baseNumbers:
			for i in xrange(10):
				newNumber = str(i) +  baseNumber
				i = int(newNumber[::-1] + newNumber)
				ii = i*i
				if IsPalindrom(i) and IsPalindrom(ii):
					fairAndSquare.append(i)
					newbaseNumbers.append(newNumber)
					#print i,ii
				i = int(newNumber[::-1][:-1] + newNumber)
				ii = i*i
				if IsPalindrom(ii) and IsPalindrom(i):
					fairAndSquare.append(i)
					newbaseNumbers.append(newNumber)
					#print i,ii
		baseNumbers = list(set(newbaseNumbers))
		
		#print len(str(B))
		#print min([len(i) for i in baseNumbers])
		if min([len(i) for i in baseNumbers]) * 4 > 110:
			break
			
			
	fairAndSquare = list(set(fairAndSquare))
	
	
	
	
def SolveC(A, B, caseNumber):

	global result
	global fairAndSquare
	
	
	
	#print caseNumber
	#print A,B
	
	
	count = 0
	for fairAndSquareNumber in fairAndSquare:
		realFairAndSquareNumber = fairAndSquareNumber ** 2
		if realFairAndSquareNumber >= A and realFairAndSquareNumber <= B:
			#print realFairAndSquareNumber
			count += 1
		
	result += "Case #%d: %d\n" %(caseNumber, count)
	return
	
	
	



















file = open(INPUT_FILE, 'rb').read()

fileLines = file.split('\n')

T = int(fileLines[0])
nextLine = 1

result = ""

FindAllFair()

for t in xrange(T):

	(A,B) = fileLines[nextLine].split(' ')
	(A,B) = (int(A), int(B))
	nextLine += 1
	
	
	SolveC(A, B, t+1)
	
	
open(OUTPUT_FILE, "wb").write(result)

