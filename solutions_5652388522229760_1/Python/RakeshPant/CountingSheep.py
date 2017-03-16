#actual logic to read data and print it by calling getOutputString function
outputList = []

with open ('C:/Users/rpant/Desktop/Python_Programs/CountingSheep/input.txt') as data :
	totalNumberOfCases = data.readline()
	for index in range (int(totalNumberOfCases)):
		integerList = set()
		testCaseStr = data.readline().strip()
		testCaseNbr = int(testCaseStr)
		if testCaseNbr == 0:
			outputList.append("INSOMNIA")
			continue
		else:
			for index in range (1, 10000):
				newNumber = testCaseNbr*index
				for ch in str(newNumber):
					integerList.add(ch) # will print each digit in order
				if len(integerList) == 10:
					outputList.append(newNumber)
					break

with open ('C:/Users/rpant/Desktop/Python_Programs/CountingSheep/output.txt', "w") as os :	
	for index in range(len(outputList)):	
		print('Case #' + str(index+1) + ': ' + str(outputList[index]), file=os)