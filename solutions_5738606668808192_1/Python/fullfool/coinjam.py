import math
primeFile = open('primeList.txt').read().split('\n')
primeList = primeFile[0].split()
primeList =  map(int, primeList)


def findCoinJam(N, J):
	biggestMiddle = (2 ** (N - 2)) - 1
	foundNum = 0
	totalList = []
	while foundNum <= 500:
	#for i in range(0, biggestMiddle):
		oriMiddlePart = str(bin(i))[2:]
		middlePart = addToLength(N-2, oriMiddlePart)
		totalNumber = '1' + middlePart + '1'
		resultList = [int(totalNumber)]
		hasPrime = False
		for base in range(2, 11):
			print 'verifying %s on base %s' % (totalNumber, base)
			tmpNum = calNum(base, totalNumber)
			tmpDivisor = findDivisor(tmpNum)
			if tmpDivisor == -1:
				hasPrime = True
				break
			resultList.append(tmpDivisor)
		if hasPrime:
			continue
		if len(resultList) == 10:
			foundNum += 1
			print 'found' + str(foundNum) +',' + totalNumber
			totalList.append(resultList)
		#if foundNum == J:
			#break
	return totalList




def findDivisor(number):
	global primeList
	if number in primeList:
		print str(number) + 'is a prime'
		return -1
	sqrtNum = int(math.sqrt(number))
	for i in range(len(primeList)):
		print 'trying to divide %s by %s' % (number, primeList[i])
		if primeList[i] >= number:
			return -1
		if number % primeList[i] == 0:
			return primeList[i]
	return -1


def calNum(base, number):
	# nLen = len(number)
	# result = 0
	# for i in range(nLen):
	# 	result *= base
	# 	result += int(number[i])
	# return result
	if base == 10:
		return int(number)
	digitList = list(number)
	digitList.reverse()
	digitList = map(int, digitList)
	
	#print digitList
	nLen = len(digitList)
	result = 0
	for i in range(nLen):
		#print digitList[i]
		if digitList[i] == 1:
			result += calExp(base, i)
		#	print calExp(base, i)
		#print calExp(base, i)
	return result


def calExp(base, expNum):
	if expNum <= 5:
		return base ** expNum
	if expNum % 2 == 0:
		return (calExp(base, expNum/2) ) ** 2
	else:
		return ((calExp(base, expNum/2)) ** 2 ) * base

#print calNum(2, '10000001000111011111')
#exit()
def addToLength(totalLength, inputStr):
	if len(inputStr) == totalLength:
		return inputStr
	return '0' * (totalLength - len(inputStr)) + inputStr


# print calNum(9, '100000000000000000000000000000001')
# exit()







if __name__ == "__main__":



	inputfile = open('C-small-attempt0.in').read().split('\n')
	filehandler = open('large.out', 'w')

	inputLen = len(inputfile)

	currentLine = 1
	currentRound = 1
	casesNum = int(inputfile[0])
	while currentLine <= inputLen - 1:
		if len(inputfile[currentLine]) == 0:
			break
		#print len(inputfile[currentLine])
		N = int(inputfile[currentLine].split()[0])
		J = int(inputfile[currentLine].split()[1])


		print 'start to work'
		totalList = findCoinJam(N, J)
		# print totalList
		# for i in range(2,11):
		# 	print calNum(i, '100011')

		filehandler.write('Case #%s:\n' % currentRound)
		


		for i in range(J):
			for j in range(10):
				if j < 9:
					filehandler.write('%s ' % totalList[i][j])
				else:
					filehandler.write('%s\n' % totalList[i][j])
	

		currentRound += 1
		currentLine += 1
	filehandler.close()






