#! /usr/bin/env python

######################
## OVATION
######################
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
	# yields (maxS, sDigits)
	with open(fname, "r") as ins:
		N = int(ins.readline())
		for i in range(N):
			raw_input = ins.readline()
			raw_input = raw_input.split()
			maxS = int(raw_input[0])
			sDigits = int(raw_input[1][::-1])
			assert len(raw_input[1]) == maxS+1

			yield (maxS, sDigits)
	return



def ALGORITHM(test_case):
	# test_case = (maxS, sDigits)
	maxS = test_case[0]
	sDigits = test_case[1]
	#sI = the parsed digits
	sI = []
	while(sDigits > 0):
		sI.append(sDigits % 10)
		sDigits = sDigits / 10

	assert len(sI) == maxS + 1
	count = 0
	totalStanding = 0
	for shyLevel in range(len(sI)):
		if totalStanding < shyLevel:
			toAdd = shyLevel - totalStanding
			totalStanding += toAdd
			count += toAdd

		# now calculate spill over
		totalStanding += sI[shyLevel]

	return str(count)






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
