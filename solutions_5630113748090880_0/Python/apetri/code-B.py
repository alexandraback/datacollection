#!/usr/bin/env python
from __future__ import division
import sys

import numpy as np

def missingList(N,lines):

	numbers_seen = dict()
	for n in lines.flatten():
		if n in numbers_seen:
			numbers_seen[n] += 1
		else:
			numbers_seen[n] = 1

	missing = list()
	for n in numbers_seen:
		if numbers_seen[n]%2:
			missing.append(n)

	missing.sort()
	assert len(missing)==N

	return " ".join([str(c) for c in missing])

#####################
#########Main########
#####################

line = lambda : sys.stdin.readline().strip("\n")

def main():

	#Number of test cases
	ntest = int(line())

	#Cycle over test cases
	for t in range(ntest):
		
		#Read in N
		N = int(line())
		lines = np.zeros((2*N-1,N),dtype=np.int)
		for r in range(2*N-1):
			lines[r] = [ int(c) for c in line().split(" ") ]

		#Calculate answer and output
		sys.stdout.write("Case #{0}: {1}\n".format(t+1,missingList(N,lines)))

if __name__=="__main__":
	main()