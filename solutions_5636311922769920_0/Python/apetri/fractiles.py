#!/usr/bin/env python

from __future__ import division
import sys

import numpy as np

def lookToPositions(K,C,S):
	min_looks = K//C + ((K%C)>0)
	
	if S<min_looks:
		return "IMPOSSIBLE"

	look_into = np.ones(min_looks,dtype=np.int64)
	positions_to_cover = range(K)
	
	for n,p in enumerate(positions_to_cover):
		look_into[n//C] += p*(K**(C-1-n%C))

	return " ".join([ str(d) for d in look_into])

#####################
#########Main########
#####################

line = lambda : sys.stdin.readline().strip("\n")

def main():

	#Number of test cases
	ntest = int(line())

	#Cycle over test cases
	for t in range(ntest):
		
		#Read the data
		K,C,S = [int(c) for c in line().split(" ")]

		#Calculate answer and output
		sys.stdout.write("Case #{0}: {1}\n".format(t+1,lookToPositions(K,C,S)))

if __name__=="__main__":
	main()