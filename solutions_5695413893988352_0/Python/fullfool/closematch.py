def getScoreList(score, resultList):
	if not '?' in score:
		resultList.append(score)
		return
	
	questionIndex = score.find('?')

	for i in range(10):
		score = score[:questionIndex] + str(i) + score[questionIndex+1:]
		getScoreList(score[:questionIndex] + str(i) + score[questionIndex+1:], resultList)




def process(cscore, jscore):
	cScoreList = []
	getScoreList(cscore, cScoreList)
	jScoreList = []
	getScoreList(jscore, jScoreList)
	minDiff = 2147483645
	minCscore = '2147483647'
	minJscore = '2147483647'
	for eachCScore in cScoreList:
		for eachJScore in jScoreList:
			#print max(int(eachCScore) - int(eachJScore), int(eachJScore)-int(eachCScore))
			if max(int(eachCScore) - int(eachJScore), int(eachJScore)-int(eachCScore)) < minDiff:
				minDiff = max(int(eachCScore) - int(eachJScore), int(eachJScore)-int(eachCScore))
				minCscore = eachCScore
				minJscore = eachJScore
			elif max(int(eachCScore) - int(eachJScore), int(eachJScore)-int(eachCScore)) == minDiff:
				if eachCScore < minCscore:
					minCscore = eachCScore
				elif eachCScore == minCscore:
					if eachJScore < minJscore:
						minJscore = eachJScore
				else:
					pass
			else:
				pass
	return minCscore, minJscore
























if __name__ == "__main__":
	inputfile = open('B-small-attempt0.in').read().split('\n')
	filehandler = open('small.out', 'w')

	inputLen = len(inputfile)

	currentLine = 1
	currentRound = 1
	casesNum = int(inputfile[0])
	while currentLine <= inputLen - 1:
		if len(inputfile[currentLine]) == 0:
			break
		#print len(inputfile[currentLine])
		twoInputList = inputfile[currentLine]
		first = twoInputList.split()[0]
		second = twoInputList.split()[1]
		cscore, jscore = process(first, second)

		print 'Case #%s: %s %s' % (currentRound, cscore, jscore)
		filehandler.write('Case #%s: %s %s\n' % (currentRound, cscore, jscore))
		currentRound += 1
		currentLine += 1
	filehandler.close()





