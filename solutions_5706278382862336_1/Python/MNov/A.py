from fractions import gcd

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
	
def testsAsPQ(filename,linesPerTest):
	data = divideIntoTests(filename,linesPerTest)
	updated = []
	for test in data:
		updated.append(map(int,test[0].split('/')))
	return updated
	
def powerOfTwo(num):
	while num > 1:
		if num%2 != 0:
			return False
		num /= 2.0
	return True
	
def reduce(Q,P):
	g = gcd(Q,P)
	while g > 1:
		Q,P = Q/g,P/g
		g = gcd(Q,P)
	return Q,P
	
def solve(filename):
	data = testsAsPQ(filename,1)
	f = open(filename+' output','w')
	for i in range(len(data)):
		Q,P = reduce(data[i][1],data[i][0])
		if not (powerOfTwo(Q)):
			f.write('Case #%d: impossible\n' % (i+1))
		else:
			answer = 1
			while data[i][1] > data[i][0] * 2**answer:
				answer += 1
			f.write('Case #%d: %d\n' % (i+1,answer))