fin = open('input.txt')
lines = fin.read().split("\n")

countTests = int(lines[0])

for testCase in range(1, countTests + 1):
	line = [float(x) for x in lines[testCase].split()]

	farmCost = line[0]
	farmRate = line[1]
	totalCost = line[2]

	curRate = 2
	curTime = 0

	while True:
		timeToTotal = totalCost / curRate
		timeToFarm = farmCost / curRate

		if timeToFarm + totalCost / (curRate + farmRate) < timeToTotal:
			# buy farm
			curRate += farmRate
			curTime += timeToFarm
		else:
			# wait for total
			curTime += timeToTotal
			break

	print "Case #" + str(testCase) + ": " + str(curTime)