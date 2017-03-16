def findSet(K, C, S):
	if K % C == 0 and S < K / C:
		return 'IMPOSSIBLE'
	if K % C != 0 and S <= K / C:
		return 'IMPOSSIBLE'
	resultList = []

	startIndex = 1
	while startIndex <= K:
		tmpList = [i for i in range(startIndex, startIndex + C)]
		tmpResultIndex = findFinalIndex(K, tmpList)
		resultList.append(tmpResultIndex)
		startIndex += C
	return resultList





def findFinalIndex(originalK, indexList):
	C = len(indexList)
	result = 0
	for i in range(C):
		opNum = indexList[i]
		if opNum > originalK:
			opNum = 1
		result += (opNum-1) * (originalK ** (C-1-i))
	return result+1




if __name__ == "__main__":
	inputfile = open('D-large.in').read().split('\n')
	filehandler = open('fractiles_large.out', 'w')

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

		resultList = findSet(K, C, S)
		if resultList == 'IMPOSSIBLE':
			filehandler.write('IMPOSSIBLE\n')
		else:
			resultLen = len(resultList)
			for i in range(resultLen):
				if i != resultLen - 1:
					filehandler.write(str(resultList[i]) + ' ')
				else:
					filehandler.write(str(resultList[i]) + '\n')
		currentRound += 1
		currentLine += 1
	filehandler.close()




