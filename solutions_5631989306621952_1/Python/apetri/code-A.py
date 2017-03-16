#!/usr/bin/env python
from __future__ import division
import sys

sys.setrecursionlimit(1000000)

def lastWord(S):
	if len(S)==1:
		return S
	else:
		optimal = lastWord(S[:-1])
		if S[-1]>=optimal[0]:
			return S[-1]+optimal
		else:
			return optimal+S[-1]

#####################
#########Main########
#####################

line = lambda : sys.stdin.readline().strip("\n")

def main():

	#Number of test cases
	ntest = int(line())

	#Cycle over test cases
	for t in range(ntest):
		
		#Read S
		S = line()

		#Calculate answer and output
		sys.stdout.write("Case #{0}: {1}\n".format(t+1,lastWord(S)))

if __name__=="__main__":
	main()