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
	# yields (L, X, chars)
	with open(fname, "r") as ins:
		N = int(ins.readline())
		for i in range(N):
			raw_data = ins.readline()
			L, X = map(int, raw_data.split())
			chars = ins.readline().split()[0]
			assert len(chars) == L
			yield (L, X, chars)
	return

table = [ 	[('1',1), ('i', 1), ('j', 1), ('k', 1) ],
			[('i',1), ('1', -1), ('k', 1), ('j', -1) ],
			[('j',1), ('k', -1), ('1', -1), ('i', 1) ],  
			[('k',1), ('j', 1), ('i', -1), ('1', -1) ] ]  

def Product(p1, p2):
	# (Char,sign), (Char,sign) -> (Char, sign)
	if p1[0] == '1':
		return (p2[0], p2[1]*p1[1])
	if p2[0] == '1':
		return (p1[0], p1[1]*p2[1])

	else:
		p1Index = ord(p1[0]) - ord('h')
		p2Index = ord(p2[0]) - ord('h')
		#print p1Index, p2Index
		iResult = table[p1Index][p2Index]
		result = (iResult[0], iResult[1] * p1[1] * p2[1])
		return result


def testProduct():
	one = ('1',1)
	i = ('i', 1)
	j = ('j', 1)
	k = ('k', 1)

	oneNeg = ('1', -1)
	iNeg = ('i', -1)
	jNeg = ('j', -1)
	kNeg = ('k', -1)

	assert Product(one, one) == one
	assert Product(i, j) == k
	assert Product(j, k) == i
	assert Product(k, i) == j

	assert Product(j, i) == kNeg
	assert Product(k, j) == iNeg
	assert Product(i, k) == jNeg

	assert Product(iNeg, i) == one
	assert Product(jNeg, j) == one
	assert Product(kNeg, k) == one

	print "product tests passed"

def wordProduct(s):
	# find accumulated product of string s

	# start with identity
	result = ('1',1)

	for c in s:
		toMultiply = (c, 1)
		result = Product(result, toMultiply)

	return result

def testWordProduct():

	assert wordProduct("i") == ('i', 1)
	assert wordProduct("j") == ('j', 1)
	assert wordProduct("k") == ('k', 1)

	assert wordProduct("jij") == ('i', 1)
	assert wordProduct("iji") == ('j', 1)
	assert wordProduct("jijiji") == ('k', 1)

	# some identity tests

	s1 = "ijkkjkjkji"

	assert wordProduct(s1*4) == ('1',1)

	s2 = "iiijjkjkjkjkjkikjjikjikjijikjijikjikjjikjikjikjik"

	assert wordProduct(s2*4) == ('1',1)

	print "word product tests complete"




def fastEvalRepeat(w, X):
	# quickly evaluate wordProduct(wwww...ww), where w occurs X times
	# can do this because w^4 = 1 for any w	

	if X % 4 == 0:
		return ('1',1)

	interProd = wordProduct(w)

	if X % 4 == 1:
		return 	interProd

	if X % 4 == 2:
		return Product(interProd, interProd)

	if X % 4 == 3:
		return Product(interProd, Product(interProd, interProd))

	## should never get here
	assert False

	return 

def ALGORITHM(test_case):
	# test_case = (L, X, chars)
	L, X, chars = test_case
	assert len(chars) == L

	if fastEvalRepeat(chars, X) != ('1', -1):
		return "NO"

	if canIJKPart(chars, X):
		return "YES"
	return "NO"

def canIJKPart(chars, X):

	start = ('1', 1)
	i = ('i', 1)
	index = 0
	tries = 6
	while X > 0 and tries >= 0:
		start = Product(start, (chars[index], 1))
		if start == i:
			return canJKPart(chars, X, index)
		else:
			index = index + 1
			if index == len(chars):
				index = 0
				X = X - 1
				tries = tries - 1
	return False

def canJKPart(chars, X, offset):
	start = ('1', 1)
	j = ('j', 1)
	index = offset + 1
	if index == len(chars):
		index = 0
		X = X - 1
	tries = 6
	while X > 0 and tries >= 4:
		start = Product(start, (chars[index], 1))
		if start == j:
			if index < len(chars) - 1 or X > 1:
				return True
		else:
			index = index + 1
			if index == len(chars):
				index = 0
				X = X - 1
				tries = tries - 1
	return False

def runAlgorithm(argv):
	#testProduct()
	#testWordProduct()
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
