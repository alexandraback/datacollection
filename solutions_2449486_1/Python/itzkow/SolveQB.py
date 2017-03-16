INPUT_FILE = "B-large.in"
OUTPUT_FILE = "B-large.out"

import math

global result





def SolveB(A, N, M, caseNumber):

	global result
	
	
	
	
	#print caseNumber
	#print N,M
	#print A
	
	rowMax = []
	for i in xrange(N):
		rowMax.append(max(A[i]))
		
	colMax = []
	for j in xrange(M):
		currentMax = A[0][j]
		for i in xrange(N):
			currentMax = max(currentMax, A[i][j])
		colMax.append(currentMax)
		
	for i in xrange(N):
		for j in xrange(M):
			if A[i][j] > rowMax[i] or A[i][j] > colMax[j]:
				print i,j, 'Weird'
			if A[i][j] != rowMax[i] and A[i][j] != colMax[j]:
				result += "Case #%d: %s\n" %(caseNumber, 'NO')
				return
	
	
	
	result += "Case #%d: %s\n" %(caseNumber, 'YES')
	return
	
	
	



















file = open(INPUT_FILE, 'rb').read()

fileLines = file.split('\n')

T = int(fileLines[0])
nextLine = 1

result = ""

for t in xrange(T):

	(N,M) = fileLines[nextLine].split(' ')
	(N,M) = (int(N), int(M))
	nextLine += 1
	
	A = []
	for i in xrange(N):
		row = fileLines[nextLine].split(' ')
		row = [int(k) for k in row]
		A.append(row)
		nextLine += 1
	
	
	SolveB(A, N, M, t+1)
	
	
open(OUTPUT_FILE, "wb").write(result)

