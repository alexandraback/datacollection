f = open('small34.in')
T = int(f.readline().strip())

for k in range(T):
	num = int(f.readline().strip())
	temp = f.readline().strip()
	oneList = [int(alpha) for alpha in temp.split()]
	maxPeople = 0
	lines = []
	pairList = {}
	lastPersonInLine = []
	firstPersonInLine = []
	# print oneList
	for i in range(len(oneList)):
		#print "Iteration: %d" %i
		friend = oneList[i]-1
		alreadySeated = {i+1:1, friend+1:1}
		#print friend
		#print oneList[oneList[friend]-1]-1
		while friend!= i and friend != oneList[oneList[friend]-1]-1:
			#print alreadySeated
			friend = oneList[friend]-1
			if friend+1 in alreadySeated:
				break
			alreadySeated[friend+1] = 1
		#print "HELLO"
		#print friend
		#print oneList[friend]-1
		if (friend == oneList[oneList[friend]-1]-1):
			if (i+1 != oneList[friend]):
				firstPersonInLine.append(i+1)
			else:
				firstPersonInLine.append(friend+1)
			lastPersonInLine.append(oneList[friend])
			if friend+1<oneList[friend]:
				pair = (friend+1,oneList[friend])
			else:
				pair = (oneList[friend],friend+1)
			if pair not in pairList:
				pairList[pair]=1
			alreadySeated[friend+1]=1
			friend = oneList[friend]-1
			alreadySeated[friend+1]=1
			lines.append(alreadySeated)
	#print lines
	#print pairList
	#print lastPersonInLine
	allLineNums = 0
	
	realLastPersonInLine = []
	allLinesSeated = {}
	for key, value in pairList.iteritems():
		item = key[0]
		#print item
		maxNum = 0
		idx = 0
		real = 0
		for line in lines:
			#print line
			if item in line:
				num = len(line.keys())
				#print "NUM: %d" %num
				if num > maxNum:
					maxNum = num
					real = lastPersonInLine[idx]
					real2 = firstPersonInLine[idx]
					lastDict = line
			idx+=1
		allLineNums+=maxNum
		realLastPersonInLine.append(real)
		realLastPersonInLine.append(real2)
		allLinesSeated.update(lastDict)
	# print realLastPersonInLine
	#print allLinesSeated
	while len(realLastPersonInLine)>0:
		#print realLastPersonInLine
		#print allLinesSeated
		#print i
		i = realLastPersonInLine.pop(0)
		#print i
		for j in range(len(oneList)):
			if oneList[j] == i:
				if j+1 not in allLinesSeated:
					allLinesSeated[j+1]=1
					realLastPersonInLine.append(j+1)
					# print j+1
					allLineNums+=1
					break
	for i in range(len(oneList)):
		friend = oneList[i]-1
		numPeople = 1
		alreadySeated = {friend:1}
		done = True
		allSeated = [friend]
		while friend != i:
			friend = oneList[friend]-1
			if friend in alreadySeated:
				done = False
				break
			else:
				alreadySeated[friend] = 1
			numPeople+=1
		if done:
			if numPeople > maxPeople:
				maxPeople = numPeople
	# print lines
	if allLineNums > maxPeople:
		print "Case #%d: %s" %(k+1, allLineNums)
	else:
		print "Case #%d: %s" %(k+1, maxPeople)

