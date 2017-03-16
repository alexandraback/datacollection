
import sys
import time
import operator
import math
import re
import heapq
from collections import deque

timeit = 1
debugv = 0
startTime = 0

outFile = open('output.txt', 'w')
inFile = sys.stdin
inFile = open('B-test.in', 'r')
inFile = open('C:/Users/quentin/Downloads/B-small-attempt3.in', 'r')
#inFile = open('C:/Users/quentin/Downloads/B-large.in', 'r')

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

MAX = [1]
S = 1
for i in range(0,52):
	MAX.append(S)
	S += S

def make(l, B, T):
	for i in range(B-l-1, B-1):
		for j in range(i+1, B):
			T[i][j] = 1

def doCase(case):
	B, M = [int(x) for x in inFile.readline().split()]
	if M > MAX[B-1]:
		out('IMPOSSIBLE')
		return
	T = []
	for i in range(B):
		T.append([0]*B)
	l = math.floor(math.log2(M)) + 1
	
	#if l > 1 and l >= B:
	#	out('IMPOSSIBLE')
	#	return

	out('POSSIBLE')
	make(l, B, T)
	S = str(bin(M))[2:]
	i = 1

	if B-l-2 >= 0:
		for s in S:
			if s == '1':
				T[0][B-l-2+i] = 1
			i += 1

	for t in T:
		out('\n')
		for i in t:
			out(str(i))


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