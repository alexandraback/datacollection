import sys

inputLists = []
depthLists = []
outputLists = []

try:
	inputFileName = sys.argv[1]
	outputFileName = inputFileName[:sys.argv[1].find('.')]+'.out'
except:
	print 'input filename as argv'
	exit()

try:
	inputFile = open("./"+inputFileName)
	inputLines = inputFile.readlines()
	caseCount = 0
	lineCount = 0
	isFirstLine = True
	rowCount = 0
	cols = 0
	D = 0
	inputLines.pop(0)
	for inputLine in inputLines:
		if isFirstLine:
			if not inputLine == '':
				lineCount = 0
				dummy1 = inputLine.split()
				rowCount = int(dummy1[0])
				cols = int(dummy1[1])
				D = int(dummy1[2])
				inputLists.append([])
				depthLists.append(D)
				isFirstLine = False
			else:
				continue
		else:
			inputLists[caseCount].append(inputLine[:cols])
		if lineCount == rowCount:
			isFirstLine = True
			caseCount += 1
			lineCount = 0
		else:
			lineCount += 1
	inputFile.close()
except:
	print 'read error'
	exit()

def getSetting(inputList):
	W = len(inputList[0])-2
	H = len(inputList)-2
	A = 0.0
	B = 0.0
	for x in range(len(inputList)):
		for y in range(len(inputList[0])):
			if inputList[x][y] == 'X':
				A = y-0.5
				B = x-0.5
	return [A, B, W, H]

def getDistance(A, B, W, H, M, N):
	Aprime = M*W
	Bprime = H*N
	if M % 2:
		Aprime += W-A
	else:
		Aprime += A
	if N % 2:
		Bprime += H-B
	else:
		Bprime += B
	return pow(pow(A-Aprime, 2)+pow(B-Bprime, 2), 0.5)

def getTangent(A, B, W, H, M, N):
	Aprime = M*W
	Bprime = H*N
	if M % 2:
		Aprime += W-A
	else:
		Aprime += A
	if N % 2:
		Bprime += H-B
	else:
		Bprime += B
	flag = ''
	if Aprime > A and Bprime > B:
		flag = '1'
	elif Aprime < A and Bprime > B:
		flag = '2'
	elif Aprime < A and Bprime < B:
		flag = '3'
	elif Aprime > A and Bprime < B:
		flag = '4'
	elif Aprime == A:
		if Bprime > B:
			flag = '+B'
		else:
			flag = '-B'
	elif Bprime == B:
		if Aprime > A:
			flag = '+A'
		else:
			flag = '-A'
	if Aprime == A or Bprime == B:
		return [flag, 0]
	else:
		return [(Bprime-B)/(Aprime-A), flag]

for x in range(len(inputLists)):
	inputList = inputLists[x]
	xyList = []
	A = 0.0
	B = 0.0
	W = 0
	H = 0
	[A, B, W, H] = getSetting(inputList)

	D = depthLists[x]

	for M in range(-50, 51):
		for N in range(-50, 51):
			if M == 0 and N == 0:
				continue
			if getDistance(A, B, W, H, M, N) > D:
				pass
			else:
				dummy1 = getTangent(A, B, W, H, M, N)
				dummy2 = 0
				try:
					dummy2 = xyList.index(dummy1)
				except:
					xyList.append(dummy1)
#	print xyList
	result = len(xyList)
	outputLists.append([result])

try:
	outputFile = open("./"+outputFileName, "w")
	outputFile.close()
except:
	pass

try:
	outputFile = open("./"+outputFileName, "a")
	output_str = ''

	for x in range(len(outputLists)):
		outputFile.write('Case #' + str(x+1)+': '+str(outputLists[x][0])+"\n")
		print x
	outputFile.close()
except:
	print 'write error'
	exit()
