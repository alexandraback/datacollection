
def getInputCases():
	inputFile = open('input.txt', 'r')
	lines = [line.strip('\n') for line in inputFile]
	lines.pop(0)
	hashmaps = []
	for line in lines:
		hashmap = {}
		for c in line:
			number = hashmap.get(c, 0)
			hashmap[c] = number + 1
		hashmaps.append(hashmap)

	return hashmaps

def solveCases(cases):
	listOfLetters = [
	("ZERO", "Z", "0"),
	("EIGHT", "G", "8"),
	("SIX", "X", "6"),
	("TWO", "W", "2"),
	("FOUR", "U", "4"),
	("THREE", "R", "3"),
	("ONE", "O", "1"),
	("FIVE", "F", "5"),
	("SEVEN", "V", "7"),
	("NINE", "I", "9")
	]
	results = []
	for j,case in enumerate(cases):
		result = []
		print j,case
		for listOfLetter in listOfLetters:
			numberOfLetter = case.get(listOfLetter[1], 0)
			for letter in listOfLetter[0]:
				case[letter] = case.get(letter, 0) - numberOfLetter
			for i in range(numberOfLetter):
				result.append(listOfLetter[2])
		print j,case
		result.sort()
		results.append(result)
	return results

def outputResults(results):
	outputFile = (open('output.txt', 'w'))
	for i, result in enumerate(results):
		outputFile.write('Case #' + str(i+1) + ': ')
		for s in result:
			outputFile.write(s)
		outputFile.write('\n')
	outputFile.close()

inputCases = getInputCases()
print inputCases
output = solveCases(inputCases)
outputResults(output)

"""
Count number of each letter
	
"""