
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
inFile = open('test.in', 'r')
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
	A, B, K= [int(x) for x in inFile.readline().split()]

	if A <= K or B <= K:
		out(str(A*B))
		return

	count = K*A + K*B - K*K
	for i in xrange(K,A):
		for j in xrange(K,B):
			#print(str(i)+" & "+str(j)+" = "+bin(i)+" & "+bin(j)+" = "+str(bin(i&j)))
			if i & j < K:
				count += 1
	out(str(count))

			

	




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
		sys.stderr.write("Completed in {} seconds.\n".format(time.clock() - startTime)) 