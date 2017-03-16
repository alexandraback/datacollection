f = open('small4.in')
T = int(f.readline().strip())

i = 0
for j in range(T):
	i+=1
	case = f.readline().split(" ")
	K = int(case[0])
	C = int(case[1])
	S = int(case[2])
	allNumbersNeeded = []
	numNow = 1
	while (numNow <= K):
		currentNum = numNow
		currentSlots = K
		for k in range(C-1):
			numNow+=1
			if (numNow > K):
				break
			currentNum = currentSlots * (numNow-1) + currentNum
			currentSlots *= K
		numNow+=1
		allNumbersNeeded.append(currentNum)
	# allNumbersNeeded = []
	# for i in range(K):
	# 	allNumbersNeeded.append(i+1)
	# numSlots = 1
	# for i in range(C-1):
	# 	numSlots
	# 	newNumbersNeeded = []
	# 	for j in range(len(allNumbersNeeded)/2):
	# 		newNumbersNeeded.append
	# numNeeded = 0
	# tempK = K

	# while (tempK > 1):
	# 	tempK = -(-tempK // 2)
	# 	numNeeded += 1
	# print numNeeded
	if (len(allNumbersNeeded) > S):
		print "Case #%d: IMPOSSIBLE" %i
	else:
		print "Case #%d: " %i + " ".join(str(item) for item in allNumbersNeeded)