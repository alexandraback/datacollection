
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
inFile = open('A-test.in', 'r')
inFile = open('C:/Users/quentin/Downloads/A-small-attempt0.in', 'r')
inFile = open('C:/Users/quentin/Downloads/A-large.in', 'r')

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
	N = int(inFile.readline())
	if N == 0:
		out('INSOMNIA')
		return
	digits = set()
	c = 0
	while len(digits) < 10:
		c += 1
		for i in str(N * c):
			digits.add(i)
	out(str(N * c))
	print(' '+str(c))
	




	#out(str(count))






def debug(m):
	if debugv:
		sys.stdout.write(m)

if __name__ == '__main__':
	if len(sys.argv) > 1:
		if re.search('d', sys.argv[1]):
			debugv = 1
		if re.search('i', sys.argv[1]):
			inFile = sys.stdin

	main()
	if timeit:
		sys.stdout.flush()
		sys.stderr.write("Completed in {} seconds.\n".format(time.clock() - startTime)) 