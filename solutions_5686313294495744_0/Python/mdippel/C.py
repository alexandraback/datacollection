#! /usr/bin/env python

import sys, getopt
import itertools
from collections import defaultdict as dd

#######################
## I/O functions begin
def processInput():
	# yields test cases
	T = int(raw_input())
	for i in range(T):
		N = int(raw_input())
		topics = []
		for _ in range(N):
			a, b = map(str, raw_input().split())
			topics.append((a,b))
		yield topics
	return


def writeOutput(results):
	for result in results:
		print result
	return
## I/O functions begin
#######################

def all_bisections(L):
	for i in range(2**len(L)):
		b = bin(i)[2:]
		if len(b) < len(L):
			b = "0" * (len(L) - len(b)) + b
		#print b
		A = []
		B = []
		for i in range(len(L)):
			if b[i] == "1":
				A.append(L[i])
			else:
				B.append(L[i])
		yield (A, B)


def ALGORITHM(test_case):
	topics = test_case
	best = 0
	for A, B in all_bisections(topics):
		#print A, B
		PRE, POST = {}, {}
		for (x,y) in B:
			PRE[x] = True
			POST[y] = True
		bad = False
		for (x,y) in A:
			if bad:
				break
			if x not in PRE or y not in POST:
				bad = True
		if not bad:
			best = max(best, len(A))
	return str(best)



def runAlgorithm():
	results = []
	for test_case in processInput():
		results.append(ALGORITHM(test_case))

	for i in range(len(results)):
		results[i] = "Case #" + str(i+1) + ": " + results[i] + "\n"

	writeOutput(results)

if __name__ == "__main__":

	runAlgorithm()
