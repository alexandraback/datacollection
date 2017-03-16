
# in: filename
# out: list - index i in list -> line i+1 of file (trimmed)

def readFile(filename):
	f = open(filename,'r')
	file = f.readlines()
	f.close()
	trimmedFile = [x.strip() for x in file]
	return trimmedFile
	
# in: filename
# out: list - index i in list -> case i+1 in file as list' such that index j in list' -> line j+1 in case 
	
def divideIntoTests(filename,linesPerTest):
	data = readFile(filename)
	numTestCases = int(data[0])
	testCases = [data[x*linesPerTest+1:(x+1)*linesPerTest+1] for x in xrange(0,numTestCases)]
	return testCases
	
def stringToNumbers(iter):
	return map(int,iter.split())
	
def testsAsNumbers(filename,linesPerTest):
	testCases = divideIntoTests(filename,linesPerTest)
	numberTests = []
	for testCase in testCases:
		numberTests.append([map(int,s.split()) for s in testCase])
	return numberTests
	
def board(N,M):
	board = [[0 for m in range(M)] for n in range(N)]
	return board
	
def solveOne(N,M,K):
	N,M = min(N,M),max(N,M)
	if N < 3:
		return K
	if K<5:
		return K
	if K>(N*M-4):
		return (2*N)+(2*M)-4+(K-N*M)
	length = 1
	width = 1
	stones = 4
	enc = 5
	step = 0
	while enc < K:
		if width == N - 2:
			if step == 0:
				length+=1
				enc = 2*length + 2*width + length*width - 2
			else:
				enc = 2*length + 2*width + length*width
		else:
			if step == 0:
				if width == length:
					length += 1
					enc = (4*width)+(length**2)-2
				else:
					width += 1
					enc = width*(width+4)-2
			else:
				enc += 2
		stones += 1
		step = 1 - step
		print "stones: %d, enc: %d, width: %d, length: %d" % (stones,enc,width,length)
	return stones

def solve(filename):
	data = testsAsNumbers(filename,1)
	f = open(filename+' output','w')
	for i in range(len(data)):
		N,M,K = data[i][0]
		print "case: %d" % (i+1)
		f.write("Case #%d: %d\n" % (i+1,solveOne(N,M,K)))
	f.close()