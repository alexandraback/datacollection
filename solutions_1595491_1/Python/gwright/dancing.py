def main():
	numTestCases = int(raw_input())

	for i in range(1, numTestCases+1):

		inputString = raw_input()
		inputList = inputString.strip().split()

		for index in range(len(inputList)):
			inputList[index] = int(inputList[index])

		numContestants, numSurprising, goalScore = inputList[0:3]
		scores = inputList[3:]
		scores.sort()
		
		surprisingCutoff = max(goalScore * 3 - 4, goalScore)
		normalCutoff = max(goalScore * 3 - 2, goalScore)
		numWinners = 0

		for score in scores:
			if score < surprisingCutoff:
				continue
			elif score < normalCutoff and numSurprising != 0:
				numWinners += 1
				numSurprising -= 1
			elif score >= normalCutoff:
				numWinners += 1

		print "Case #"+str(i)+": "+str(numWinners)

main()
