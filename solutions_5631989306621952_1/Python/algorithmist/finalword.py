def getFinalWordFrom(S):
	finalWord = S[0]
	for i in range(1, len(S)):
		if ord(S[i]) >= ord(finalWord[0]):
			finalWord = S[i] + finalWord
		else:
			finalWord += S[i]
	return finalWord

def main():
	inputFile = open('A-large.in', 'r')
	outputFile = open('fwOutput.txt', 'w')
	cases = int(inputFile.readline().strip())
	for i in range(cases):
		S = inputFile.readline().strip()
		finalWord = getFinalWordFrom(S)
		outputFile.write('Case #' + str(i + 1) + ': ' + finalWord + '\n')


main()
