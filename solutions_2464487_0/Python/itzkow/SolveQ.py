INPUT_FILE = "A-small-attempt0.in"
OUTPUT_FILE = "A-small-attempt0.out"

import math

global result
global caseNumber



def IsX(point):
	if point == 'X' or point == 'T':
		return True
	else:
		return False
		
def IsO(point):
	if point == 'O' or point == 'T':
		return True
	else:
		return False


def SolveA(r,t):

	global result
	global caseNumber
	
	
	
	#print caseNumber
	#print A0
	#print A1
	#print A2
	#print A3
	
	print r,t
	
	kmin = 0
	kmax = 4*(10**18)

	while (True):
		k = (kmin+kmax) / 2
		if (kmin+1 >= kmax):
			break
		s = 2*r*k + 2*k*k-k
		if (s > t):
			kmax = k
			continue
		else:
			kmin = k
			continue

	result += "Case #%d: %d\n" %(caseNumber+1, kmin)
	
	
	
	"""if (('.' in A0) or ('.' in A1) or ('.' in A2) or ('.' in A3)):
		result += "Case #%d: %s\n" %(caseNumber, 'Game has not completed')
		return
	else:
		result += "Case #%d: %s\n" %(caseNumber, 'Draw')
		return
	
	"""
	



















file = open(INPUT_FILE, 'rb').read()

fileLines = file.split('\n')

T = int(fileLines[0])
nextLine = 1

result = ""

for caseNumber in xrange(T):

	R = fileLines[nextLine]
	r,t = [int(x) for x in R.split(' ')]
	nextLine += 1
	
	SolveA(r,t)
	
	
open(OUTPUT_FILE, "wb").write(result)

