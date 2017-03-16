def findTwo(N):
	if N == 0:
		return 'INSOMNIA'
	if N < 0:
		N = 0 - N
	digitDict = {}
	digitNum = 0
	strN = str(N)
	for i in range(len(strN)):
		if digitDict.has_key(strN[i]):
			continue
		else:
			digitDict[strN[i]] = 1
			digitNum += 1
	if digitNum == 10:
		return N
	currentMultiplyer = 2
	while digitNum != 10:
		tmpN = currentMultiplyer * N
		strN = str(tmpN)
		for j in range(len(strN)):
			if digitDict.has_key(strN[j]):
				continue
			else:
				digitDict[strN[j]] = 1
				digitNum += 1
		if digitNum == 10:
			return tmpN
		currentMultiplyer += 1







if __name__ == "__main__":
	inputfile = open('A-large.in').read().split('\n')
	filehandler = open('A-large.out', 'w')

	inputLen = len(inputfile)

	currentLine = 1
	currentRound = 1
	casesNum = int(inputfile[0])
	while currentLine <= inputLen - 1:
		if len(inputfile[currentLine]) == 0:
			break
		#print len(inputfile[currentLine])
		N = int(inputfile[currentLine])
		result = findTwo(N)

		print 'Case #%s: %s\n' % (currentRound, result)
		filehandler.write('Case #%s: %s\n' % (currentRound, result))
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

