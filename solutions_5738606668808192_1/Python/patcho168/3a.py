import sympy

LENGTH = 32
DIVISORS = [3,5,7,11,13,17]

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
		if (i%2 == 1):
			returnDivisors.append(2)
			continue
		currentBase = i+2
		numInBase = convertBase(binNum, currentBase)
		done = False
		for divisor in DIVISORS:
			if (numInBase%divisor == 0):
				returnDivisors.append(divisor)
				done = True
				break
		# print numInBase
		#allDivisors = sympy.divisors(numInBase)
		#if (len(allDivisors) > 2):
		#	returnDivisors.append(allDivisors[1])
		if not done:
			break
	return returnDivisors


f = open('large3.in')
T = int(f.readline().strip())

for i in range(T):
	case = f.readline().split(" ")
	digits = int(case[0])
	# print digits
	numCasesNeeded = int(case[1])
	# print numCasesNeeded
	numCasesDone = 0
	print "Case #%d:" %(i+1)
	for j in range(2**(digits-16)):
		midBinaryNum = bin(j)[2:].zfill(digits-2)
		if (midBinaryNum.count('1') %2 == 1):
			continue
		currentBinaryNum = '1' + midBinaryNum + '1'
		# print currentBinaryNum
		# print currentBinaryNum
		allDivisors = isJamCoin(currentBinaryNum)
		# print allDivisors
		if (len(allDivisors) == 9):
			print currentBinaryNum + " " + " ".join(str(item) for item in allDivisors)
			numCasesDone += 1
			if (numCasesDone == numCasesNeeded):
				break
