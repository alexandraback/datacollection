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
	# yields test cases
	print fname
	with open(fname, "r") as ins:
		T = int(ins.readline())
		for i in range(T):
			N = int(ins.readline())
			yield N



OPT = [10**6]*(10**6+1)
OPT[0] = 0

def flip(i):
	if str(i)[-1] == '0':
		return i
	return int(str(i)[::-1])


def fill_in_opt():
	for i in range(1,10**6 + 1):
		OPT[i] = min(1 + OPT[i-1], 1 + OPT[flip(i)])
		if i < 30:
			print i, OPT[i]
	return

def ALGORITHM(test_case):
	N = test_case
	#print N
	return str(OPT[N])



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
	fill_in_opt()
	runAlgorithm(sys.argv[1:])
