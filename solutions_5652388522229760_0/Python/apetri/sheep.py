#!/usr/bin/env python

import sys

def nBeforeSleep(N):

	if N==0:
		return "INSOMNIA"

	digits = set()
	current = N
	while True:
		for d in str(current):
			digits.add(d)
		
		if len(digits)==10:
			return current

		current += N


#####################
#########Main########
#####################

line = lambda : sys.stdin.readline().strip("\n")

def main():

	#Number of test cases
	ntest = int(line())

	#Cycle over test cases
	for t in range(ntest):

		N = int(line())

		#Calculate answer and output
		sys.stdout.write("Case #{0}: {1}\n".format(t+1,nBeforeSleep(N)))

if __name__=="__main__":
	main()