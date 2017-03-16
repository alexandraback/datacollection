
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
inFile = open('D-test.in', 'r')
inFile = open('C:/Users/quentin/Downloads/D-small-attempt0.in', 'r')
#inFile = open('C:/Users/quentin/Downloads/D-large.in', 'r')
#inFile = open('C:/Users/quentin/Downloads/D-large-practice.in', 'r')
#inFile = open('/Users/quentinbramas/Downloads/D-large-practice.in', 'r')


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

def nPos(K, C, n):
	r = n
	while C > 1:
		n2 = min(n+1, K)
		r = (r-1)*K+n2
		n = n2
		C -= 1
	return r


def doCase(case):
	K, C, S = [int(x) for x in inFile.readline().split()]
	if S == K and False:
		pos = []
		for i in range(S):
			pos.append(str(i + 1))
		out(' '.join(pos))
		return

	n = math.ceil(K/C)
	if n > S:
		out('IMPOSSIBLE')
		return
	p = 1
	m = K ** C
	pos = []
	while p <= K:
		pos.append(str(nPos(K,C,p)))
		p += C
	out(' '.join(pos))



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
		sys.stdout.flush() 
		sys.stderr.write("Completed in {} seconds.\n".format(time.clock() - startTime)) 