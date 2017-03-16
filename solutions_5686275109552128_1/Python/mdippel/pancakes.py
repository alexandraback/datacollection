#! /usr/bin/env python

import sys, getopt

##################
## default reading
def writeOutput(output, fname):
	f = open(fname, 'w')
	for s in output:
		f.write(s)

def parseCommandLine(argv):
	inputfile = ''
	outputfile = ''
	try:
		opts, args = getopt.getopt(argv,"hi:o:",["ifile=","ofile="])
	except getopt.GetoptError:
		print "getting arguments error"
		print 'test.py -i <inputfile> -o <outputfile>'
		sys.exit(2)
	for opt, arg in opts:
		if opt == '-h':
			print 'test.py -i <inputfile> -o <outputfile>'
			sys.exit()
		elif opt in ("-i", "--ifile"):
			inputfile = arg
		elif opt in ("-o", "--ofile"):
			outputfile = arg
	return inputfile, outputfile

## end default reading
#######################

def processInput(fname):
	# yields (D, pancake_counts)
	with open(fname, "r") as ins:
		T = int(ins.readline())
		for i in range(T):
			D = int(ins.readline())
			counts_raw = ins.readline()
			pancake_counts = map(int, counts_raw.split())
			assert len(pancake_counts) == D
			yield (D, pancake_counts)
	return

def individualDivide(stackSize, maxStackSize):
	count = 0
	while stackSize > maxStackSize:
		stackSize -= maxStackSize
		count += 1
	return count

def timeToTake(pancake_counts, pPrime):
	toDistribute = filter(lambda x: x > pPrime, pancake_counts)
	timeToDistribute = map(lambda x: individualDivide(x, pPrime), toDistribute)

	return sum(timeToDistribute) + pPrime

def ALGORITHM(test_case):
	# test_case = (D, pancake_counts)
	D = test_case[0]
	pancake_counts = test_case[1]
	assert len(pancake_counts) == D

	# brute force pPrimes

	maxP = max(pancake_counts)
	minP = 1
	minSeen = maxP
	for pPrime in range(minP, maxP + 1):
		curr = timeToTake(pancake_counts, pPrime)
		if curr < minSeen:
			minSeen = curr

	return str(minSeen)




def runAlgorithm(argv):
	inputfile, outputfile = parseCommandLine(argv)
	if inputfile == '' or outputfile == '':
		print 'test.py -i <inputfile> -o <outputfile>'
		sys.exit(2)

	results = []
	for test_case in processInput(inputfile):
		results.append(ALGORITHM(test_case))

	for i in range(len(results)):
		results[i] = "Case #" + str(i+1) + ": " + results[i] + "\n"

	writeOutput(results, outputfile)

if __name__ == "__main__":

	runAlgorithm(sys.argv[1:])
