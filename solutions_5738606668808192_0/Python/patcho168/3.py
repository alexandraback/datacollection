import sympy

LENGTH = 16

def convertBase(binNum, currentBase):
	returnNum = 0
	currentPower = LENGTH
	for i in binNum:
		currentPower -= 1
		if (i=='1'):
			returnNum += currentBase ** currentPower 
	return returnNum

def isJamCoin(binNum):
	returnDivisors = []
	for i in range(9):
		currentBase = i+2
		numInBase = convertBase(binNum, currentBase)
		# print numInBase
		allDivisors = sympy.divisors(numInBase)
		if (len(allDivisors) > 2):
			returnDivisors.append(allDivisors[1])
		else:
			break
	return returnDivisors


f = open('small3.in')
T = int(f.readline().strip())

for i in range(T):
	case = f.readline().split(" ")
	digits = int(case[0])
	numCasesNeeded = int(case[1])
	numCasesDone = 0
	print "Case #%d:" %(i+1)
	for j in range(2**(digits-2)):
		currentBinaryNum = '1' + bin(j)[2:].zfill(digits-2) + '1'
		# print currentBinaryNum
		allDivisors = isJamCoin(currentBinaryNum)
		# print allDivisors
		if (len(allDivisors) == 9):
			print currentBinaryNum + " " + " ".join(str(item) for item in allDivisors)
			numCasesDone += 1
			if (numCasesDone == numCasesNeeded):
				break
