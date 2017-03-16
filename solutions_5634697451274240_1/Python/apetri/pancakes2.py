#!/usr/bin/env python

import sys

def minChanges(stack):

	#Flip sign
	flip = lambda c : "+" if c=="-" else "-"

	changes = 0
	current_sign = stack[0]
	for s in stack:
		if s!=current_sign:
			current_sign = flip(current_sign)
			changes += 1

	if current_sign=="-":
		changes += 1

	return changes


#####################
#########Main########
#####################

line = lambda : sys.stdin.readline().strip("\n")

def main():

	#Number of test cases
	ntest = int(line())

	#Cycle over test cases
	for t in range(ntest):
		
		stack = line()

		#Calculate answer and output
		sys.stdout.write("Case #{0}: {1}\n".format(t+1,minChanges(stack)))

if __name__=="__main__":
	main()