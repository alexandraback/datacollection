def findSet(pancakes):
	panNum = len(pancakes)
	if panNum == 0:
		return 0
	lastIndex = -1
	if pancakes[-1] == '+':
		for i in range(panNum - 1, -1, -1):
			if pancakes[i] == '+':
				continue
			else:
				lastIndex = i
				break

		return reverse(pancakes[:lastIndex + 1])
	else:
		if pancakes[0] == '-':
			newPancakes = reverseHelper(pancakes)
			return 1 + reverse(newPancakes)
		else:
			lastFaceIndex = 0
			for i in range(panNum - 1, -1, -1):
				if pancakes[i] == '-':
					continue
				else:
					lastFaceIndex = i
					break
			tmpFirstPancakes = reverseHelper(pancakes[: lastFaceIndex + 1])
			tmpSecondPancakes = pancakes[lastFaceIndex + 1:]
			newPancakes = tmpFirstPancakes + tmpSecondPancakes
			return 1 + reverse(newPancakes)




def reverseHelper(tmpStr):
	tmpList = list(tmpStr)
	for i in range(len(tmpList)):
		if tmpList[i] == '+':
			tmpList[i] = '-'
		else:
			tmpList[i] = '+'
	tmpList.reverse()
	return ''.join(tmpList)










if __name__ == "__main__":
	inputfile = open('D-small-attempt0.in').read().split('\n')
	filehandler = open('fractiles_small.out', 'w')

	inputLen = len(inputfile)

	currentLine = 1
	currentRound = 1
	casesNum = int(inputfile[0])
	while currentLine <= inputLen - 1:
		if len(inputfile[currentLine]) == 0:
			break
		#print len(inputfile[currentLine])
		thisLine = inputfile[currentLine].split()
		K = int(thisLine[0])
		C = int(thisLine[1])
		S = int(thisLine[2])
		#pancakeStr = inputfile[currentLine]
		#result = reverse(pancakeStr)

		print 'Case #%s: ' % (currentRound)
		filehandler.write('Case #%s: ' % (currentRound))

		for i in range(K):
			if i < K-1:
				filehandler.write('%s ' % (i+1))
			else:
				filehandler.write('%s\n' % (i+1))
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

