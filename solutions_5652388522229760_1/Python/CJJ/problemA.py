#Counting Sheep
import sys

def readInput (filename):
	cases = []
	with open (filename, 'r') as file:
		numberOfCases = int(file.readline())
		for i in range(numberOfCases):
			cases.append(int(file.readline()))
	return numberOfCases, cases
	
def writeOutput (filename, output, numberOfCases):
	
	with open (filename, 'w') as file:
		for i in range(numberOfCases):
			line = "Case #" + str(i+1) + ": "
			result = output[i]
			if result == 0:
				line += "INSOMNIA" + '\n'
			else:
				line += str(result) + '\n'
			file.write(line)
	

def problemA (inputfile=".input", outputfile="output"):
	numberOfCases, cases = readInput(inputfile)
	output = []
	for case in cases:
		output.append(countingSheep(case))
	writeOutput(outputfile, output, numberOfCases)
	

def countingSheep (N):
	target = set((0,1,2,3,4,5,6,7,8,9))
	if N == 0:
		return 0
	current = set()
	cont = 0
	while current != target:
		cont += 1
		current |= getDigit (cont*N)
	return cont*N
	
	
def getDigit (integer):
	digits = set()
	while integer:
		digits.add(integer%10)
		integer //= 10
	return digits
	
if __name__ == "__main__":
	problemA(sys.argv[1])