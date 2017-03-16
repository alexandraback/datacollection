import math
def findCoinJam(N, J):
	biggestMiddle = (2 ** (N - 2)) - 1
	foundNum = 0
	totalList = []
	for i in range(0, biggestMiddle):
		oriMiddlePart = str(bin(i))[2:]
		middlePart = addToLength(N-2, oriMiddlePart)
		totalNumber = '1' + middlePart + '1'
		resultList = [int(totalNumber)]
		hasPrime = False
		for base in range(2, 11):
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
		if foundNum == J:
			break
	return totalList




def findDivisor(number):
	sqrtNum = int(math.sqrt(number))
	for i in range(2, sqrtNum + 1):
		if number % i == 0:
			return i
	return -1

def calNum(base, number):
	nLen = len(number)
	result = 0
	for i in range(nLen):
		result *= base
		result += int(number[i])
	return result

def addToLength(totalLength, inputStr):
	if len(inputStr) == totalLength:
		return inputStr
	return '0' * (totalLength - len(inputStr)) + inputStr











if __name__ == "__main__":



	inputfile = open('B-large.in').read().split('\n')
	filehandler = open('small1.out', 'w')

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








	# filehandler = open('A-big-practice.out', 'w')
	# casesNum = int(raw_input())
	# for i in range(casesNum):
	# 	valueSum = int(raw_input())
	# 	itemNum = int(raw_input())

	# 	itemList = raw_input()
	# 	itemList = itemList.split()
	# 	itemList = map(int, itemList)
	# 	# for j in range(itemNum):
	# 	# 	tmpValue = int(raw_input())
	# 	# 	itemList.append(tmpValue)
	# 	index1, index2 = findTwo(valueSum, itemList)
	# 	print 'Case #%s: %s %s' % (i+1, index1, index2)
	# 	filehandler.write('Case #%s: %s %s\n' % (i+1, index1, index2))
	# filehandler.close()

