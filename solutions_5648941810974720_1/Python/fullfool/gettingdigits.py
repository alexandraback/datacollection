def deleteDigit(digitString, digit):
	numberDict = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
	for i in range(len(numberDict[digit])):
		index = digitString.find(numberDict[digit][i])
		digitString = digitString[:index] + digitString[index+1:]
	return digitString

def process(digitString):
	numberDict = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

	resultList = []

	while len(digitString) > 0:
		if 'Z' in digitString:
			zindex = digitString.find('Z')
			digitString = digitString[:zindex] + digitString[zindex+1:]
			eindex = digitString.find('E')
			digitString = digitString[:eindex] + digitString[eindex+1:]
			rindex = digitString.find('R')
			digitString = digitString[:rindex] + digitString[rindex+1:]			
			oindex = digitString.find('O')
			digitString = digitString[:oindex] + digitString[oindex+1:]
			resultList.append(0)
			continue

		if 'W' in digitString:
			tindex = digitString.find('T')
			digitString = digitString[:tindex] + digitString[tindex+1:]
			windex = digitString.find('W')
			digitString = digitString[:windex] + digitString[windex+1:]
			oindex = digitString.find('O')
			digitString = digitString[:oindex] + digitString[oindex+1:]
			resultList.append(2)

			continue

		if 'U' in digitString:
			digitString = deleteDigit(digitString, 4)
			resultList.append(4)

			continue

		if 'F' in digitString:
			digitString = deleteDigit(digitString, 5)
			resultList.append(5)

			continue

		if 'R' in digitString:
			digitString = deleteDigit(digitString, 3)
			resultList.append(3)

			continue

		if 'O' in digitString:
			digitString = deleteDigit(digitString, 1)
			resultList.append(1)

			continue
		
		if 'H'  in digitString:
			digitString = deleteDigit(digitString, 8)
			resultList.append(8)

			continue			

		if 'V' in digitString:
			digitString = deleteDigit(digitString, 7)
			resultList.append(7)

			continue	

		if 'S' in digitString:		
			digitString = deleteDigit(digitString, 6)
			resultList.append(6)

			continue

		digitString = deleteDigit(digitString, 9)
		resultList.append(9)



	resultList.sort()
	resultList = map(str, resultList)
	returnList = ''.join(resultList)
	print returnList
	return returnList


















if __name__ == "__main__":
	inputfile = open('A-large.in').read().split('\n')
	filehandler = open('large.out', 'w')

	inputLen = len(inputfile)

	currentLine = 1
	currentRound = 1
	casesNum = int(inputfile[0])
	while currentLine <= inputLen - 1:
		if len(inputfile[currentLine]) == 0:
			break
		#print len(inputfile[currentLine])
		digitString = inputfile[currentLine]
		result = process(digitString)

		print 'Case #%s: %s' % (currentRound, result)
		filehandler.write('Case #%s: %s\n' % (currentRound, result))
		currentRound += 1
		currentLine += 1
	filehandler.close()





