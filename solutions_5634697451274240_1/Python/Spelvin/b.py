def leadingpluslength(string):
	if string == '' or string[0] == '-':
		return 0
	return 1 + leadingpluslength(string[1:])

def latestminusposition(string):
	if string == '':
		return 'None'
	if string[-1] == '-':
		return len(string)-1
	return latestminusposition(string[:-1])
	
def flipallcakes(string):
	newstring = ''
	for char in string:
		if char == '+':
			newstring = '-' + newstring
		if char == '-':
			newstring = '+' + newstring
	return newstring
	
def flipsomecakes(string,pos):
	return flipallcakes(string[:(pos+1)]) + string[(pos+1):]

def flipsneeded(string):
	lmp = latestminusposition(string)
	if lmp == 'None':
		return 0
	if string[0] == '+':
		lpl = leadingpluslength(string)
		return 1 + flipsneeded(flipsomecakes(string,lpl-1))
	else:
		return 1 + flipsneeded(flipsomecakes(string,lmp))
		
import sys
with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()
		
with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):
		string = inputLines.pop(0).rstrip()
		fileOUT.write('Case #' + str(num+1) + ': ' + str(flipsneeded(string)) + '\n')