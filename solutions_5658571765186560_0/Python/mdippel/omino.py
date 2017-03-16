#! /usr/bin/env python

#########################
## OMINO
#########################

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
	# yields (X, R, C)
	with open(fname, "r") as ins:
		N = int(ins.readline())
		for i in range(N):
			raw_data = ins.readline()
			X, R, C = map(int, raw_data.split())
			yield (X, R, C)
	return


def ALGORITHM(test_case):
	# test_case = (X, R, C)
	# X = we are using X-ominos
	# R = R rows
	# C = C columns

	X, R, C = test_case

	# richard picks an X-omino
	# gabriel must pack it with other x-ominos into the R by C board

	# can richard stop him? output RICHARD
	# can gabriel always win? output GABRIEL

	# trivial check: do the dimensions match?
	if (R*C) % X != 0:
		return "RICHARD"

	# can we make an unusable block, which cannot be rotated to fit either dimension?
	for i in range(1, X+1):
		dims = (i, X-i+1)
		if max(dims) > max(R,C) or min(dims) > min(R, C):
			return "RICHARD"

	# else... can we make a block which partitions the grid in a bad way?
	# this has to be no matter how it is placed

	# for it to partition, it cant be placed flush against a wall
	# thus cant be X by 1
	# if its A by B, we must have A == min(r, c), B > min(r, c)

	A = min(R, C)
	B = X - A + 1

	# if B is greater than the smallest dimension, it has to be lined with the other
	# but A is the smallest dimension
	# so it draws a line across
	if B > min(R, C):
		if X == 2:
			return "GABRIEL"
		return "RICHARD"



	return "GABRIEL"

def runAlgorithm(argv):
	inputfile, outputfile = parseCommandLine(argv)
	if inputfile == '' or outputfile == '':
		print 'test.py -i <inputfile> -o <outputfile>'
		sys.exit(2)

	results = []
	for test_case in processInput(inputfile):
		results.append(ALGORITHM(test_case))

	for i in range(len(results)):
		results[i] = "Case #" + str(i+1) + ": " + results[i] + '\n'

	writeOutput(results, outputfile)

if __name__ == "__main__":

	runAlgorithm(sys.argv[1:])
