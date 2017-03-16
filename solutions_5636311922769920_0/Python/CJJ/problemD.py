#Fractiles
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
			if output[i] == 0:
				line += "IMPOSSIBLE" + '\n'
				file.write(line)
				continue
			for tile in output[i]:
				line += str(tile) + ' '
			line += '\n'
			file.write(line)
	

def problem (inputfile=".input", outputfile="output"):
	numberOfCases, cases = readInput(inputfile)
	output = []
	for case in cases:
		K, C, S = [int(i) for i in case.split(' ')]
		output.append(cleanStrategy(K, C, S))
	writeOutput(outputfile, output, numberOfCases)
	

def cleanStrategy (K, C, S):
	tilesToClean =[]
	tile = 0
	maxTile = K**C
	
	if K == 1:
		tilesToClean = [1]
		tile = K
	if C == 1:
		tilesToClean = [i for i in range(1,K+1)]
		tile = K
		
		
	while tile < K:
		tilesToClean.append(min((K**(C-1))*(tile)+tile+2, maxTile))
		tile += 2
		
	if len(tilesToClean) > S:
		tilesToClean = 0
	return tilesToClean

	
if __name__ == "__main__":
	problem(sys.argv[1])