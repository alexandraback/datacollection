def main():
	numTestCases = int(raw_input())
	for testCaseNum in range(1, numTestCases+1):
		inputList = raw_input().strip().split()
		for i in range(len(inputList)):
			inputList[i] = int(inputList[i])

		a,b = inputList
		print "Case #"+str(testCaseNum)+": "+str(numReversedWords(a,b))

def numReversedWords(a, b):
	resultCount = 0
	
	for num in range(a, b+1):
		num_str = str(num)
		usedRecycleds = []
		for index in range(1, len(num_str)):
			recycledNum = int(num_str[index:]+num_str[:index])
			if a <= num < recycledNum <= b and recycledNum not in usedRecycleds:
				resultCount += 1
				usedRecycleds.append(recycledNum)

	return resultCount

main()
