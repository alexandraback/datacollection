
import sys
import time
import operator
import math
import re

timeit = 1
debugv = 0
startTime = 0

outFile = open('output.txt', 'w')
inFile = sys.stdin
inFile = open('B-test.in', 'r')
inFile = open('B-small-attempt0.in', 'r')

def main():
	T = int(inFile.readline())
	startTime = time.clock()
	for case in range(1,T+1):
		out("Case #{}: ".format(case))
		doCase(case)
		out("\n")

		



def out(m):
	outFile.write(m)
	sys.stdout.write(m)

def cobin(k,n):
	#debug(str(k)+" parmi "+str(n)+"\n")
	return math.factorial(n)//(math.factorial(n-k)*math.factorial(k))


def doCase(case):
	C, F, X = [float(x) for x in inFile.readline().split()]
	V = 2.0
	addTime = 0.0

	timeToNextFarm = C/V
	timeToFinish = X/V
	timeToFinishWithAFarm = timeToNextFarm + X/(V + F)
	while timeToFinish >= timeToFinishWithAFarm:
		addTime += timeToNextFarm
		V += F
		timeToNextFarm = C/V
		timeToFinish = X/V
		timeToFinishWithAFarm = timeToNextFarm + X/(V + F)

	out(str(addTime + timeToFinish))
			

	




	#out(str(count))






def debugln(m):
	debug(m)
	debug('\n')

def debug(m):
	if debugv:
		sys.stdout.write(str(m))

if __name__ == '__main__':
	if len(sys.argv) > 1:
		if re.search('d', sys.argv[1]):
			debugv = 1
		if re.search('i', sys.argv[1]):
			inFile = sys.stdin

	main()
	if timeit:
		sys.stderr.write("Completed in {} seconds.\n".format(time.clock() - startTime)) 