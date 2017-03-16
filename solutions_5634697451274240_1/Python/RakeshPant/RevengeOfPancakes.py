#The logic to give minimum time output for each case.
def getMinumFlips(pancakeString):
	count = 0
	old_string = pancakeString

	k = old_string.find("-")
	while k != -1:
		firtChar = old_string[0]
		if firtChar == '+':
			j = old_string.find("-")
		if firtChar == '-':
			j = old_string.find("+")
		
		if j == -1:
			lString = old_string
			j = len(old_string)
		else:
			lString = old_string[:j]
			
		lString = lString.replace("-", "1")
		lString = lString.replace("+", "0")
		lString = lString.replace("0", "-")
		lString = lString.replace("1", "+")
		lString = lString[::-1]

		if (j == len(old_string)):
			old_string = lString
		else:
			old_string = lString + old_string[j:]

		count = count+1
		k = old_string.rfind("-")
	
	return count

#actual logic to read data and print it by calling getOutputString function
outputList = []

with open ('C:/Users/rpant/Desktop/Python_Programs/RevengeOfPancakes/input.txt') as data :
	totalNumberOfCases = data.readline()
	for index in range (int(totalNumberOfCases)):
		testCaseStr = data.readline().strip()
		outputList.append(getMinumFlips(testCaseStr))

with open ('C:/Users/rpant/Desktop/Python_Programs/RevengeOfPancakes/output.txt', "w") as os :	
	for index in range(len(outputList)):	
		print('Case #' + str(index+1) + ': ' + str(outputList[index]), file=os)