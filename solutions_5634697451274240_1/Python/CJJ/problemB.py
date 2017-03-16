#Revenge of the Pancakes
import sys

def readInput (filename):
	cases = []
	with open (filename, 'r') as file:
		numberOfCases = int(file.readline())
		for i in range(numberOfCases):
			cases.append(file.readline().replace('\n',''))
	return numberOfCases, cases
	
def writeOutput (filename, output, numberOfCases):
	with open (filename, 'w') as file:
		for i in range(numberOfCases):
			line = "Case #" + str(i+1) + ": "
			line += str(output[i]) + '\n'
			file.write(line)
	

def problem (inputfile=".input", outputfile="output"):
	numberOfCases, cases = readInput(inputfile)
	output = []
	for case in cases:
		output.append(pancakeFlips(case))
	writeOutput(outputfile, output, numberOfCases)
	

def pancakeFlips (pancakeStack):
	prevSide = pancakeStack[0]
	numberOfFlips = 0
	for pancakeSide in pancakeStack:		
		if prevSide != pancakeSide:
			numberOfFlips += 1
		prevSide = pancakeSide
	if prevSide=='-':
		numberOfFlips += 1
	return numberOfFlips

	
if __name__ == "__main__":
	problem(sys.argv[1])