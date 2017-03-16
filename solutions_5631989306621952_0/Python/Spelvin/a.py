def f(string):
	if len(string) == 1:
		return string
	output = string[0]
	for char in string[1:]:
		if char >= output[0]:
			output = char + output
		else:
			output = output + char
	return output

import sys
with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()
		
with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):
		string = inputLines.pop(0).rstrip()
		fileOUT.write('Case #' + str(num+1) + ': ' + f(string) + '\n')