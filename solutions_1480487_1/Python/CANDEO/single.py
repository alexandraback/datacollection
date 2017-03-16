import sys

inputLists = []
outputLists = []

def getTrans(inputList):
	N = inputList[0]
	E = getE(inputList) # num of passers even if get 0.0 percent
	X = sum(inputList[1:])
	returnList = []
	for x in range(N):
		returnList.append(getRealAnswer(X, inputList[x+1], N, E))
	return returnList

def getE(inputList):
	N = inputList[0]
	X = sum(inputList[1:])
	returnList = []
	for x in range(N):
		dummyValue = getAnswer(X, inputList[x+1], N)
		if dummyValue < 0.0:
			returnList.append(inputList[x+1])
	return returnList

def getRealAnswer(X, S, N, E):
	if S in E:
		return 0.0
	else:
		print X, S, N, E, getAnswer(X, S, N-len(E))
		return ((2.0*X-sum(E))/(N-len(E))-S)/X*100
	return 

def getAnswer(X, S, N):
#	print X, S, N
	try:
		returnValue = (2.0/int(N)) - (float(S)/int(X))
	except:
		print 'except'
		returnValue = 0.0
	return returnValue * 100

try:
	inputFileName = sys.argv[1]
	outputFileName = inputFileName[:sys.argv[1].find('.')]+'.out'
except:
	print 'input filename as argv'
	exit()

try:
	inputFile = open("./"+inputFileName)
	inputLines = inputFile.readlines()
	for inputLine in inputLines:
		# do some processes here
		dummyList = inputLine.split()
		dummyList = map(int, dummyList)
		inputLists.append(dummyList)
	inputFile.close()
except:
	print 'read error'
	exit()

inputLists.pop(0)

inputCount = 0
for inputList in inputLists:
	dummyList = []
	# do some works here
	dummyList = getTrans(inputList)
	print dummyList
	outputLists.append(dummyList[:])
	inputCount += 1
	print inputCount

#print outputLists

try:
	outputFile = open("./"+outputFileName, "w")
	outputFile.close()
except:
	pass

try:
	outputFile = open("./"+outputFileName, "a")
	output_str = ''

	for x in range(len(outputLists)):
		outputFile.write('Case #' + str(x+1)+': ')
		for y in range(len(outputLists[x])):
			if y > 0:
				outputFile.write(' ')
			outputFile.write(str(outputLists[x][y]))
		outputFile.write("\n")
	outputFile.close()
except:
	print 'write error'
	exit()
