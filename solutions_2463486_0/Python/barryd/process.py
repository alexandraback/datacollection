#!/usr/bin/python3

'''

Google Code Jam 2013
Qualification Round
Problem C - Fair and Square

Notes:
	* counting fair & square numbers in an interval
	* it's obvious from the special datasets that there are a few basic strategies we are expected to use, possibly with varying strengths and weaknesses
	* if we can figure out both before doing either problem, we could just add a check on the problem sizes at the outside, and choose the appropriate version of the code based on that
		* this would allow us to have a single program capable of handling all datasets
	* presumably we are to share calculations between cases, in order to get the best result with a large number of cases (large dataset 1)?
		* otherwise they would simply have made the number of cases the same and adjusted the problem size, and that would imply one solution was equal to or better than the other, and negate the need for the additional dataset
	* or maybe they just want to give people the opportunity to solve a large dataset, having only had either insight x or insight y, but if you have both, you can do both with the one program?
	
	* checking a single number for being fair & square is O(1) (if we assume number length in digits is limited), but iterating over the entire range provided and doing that check is still too slow (for the large datasets)
		* okay, checking a 100-digit number for fairness is actually 100 steps, and checking it for square-of-fairness is probably worse, since you're clearly not going to be using platform-native integers
	* but for once, let's do the small dataset first, with the intention to rewrite after solving it
	
	* it will be beneficial to determine the square roots of the range endpoints, and count through those, only checking the squares if the square root was found to be fair already
	* to ensure we still have the range correct, we should either:
		* round up for the lower bound and down for the upper bound, when determining the square-root range
			* this way seems better to me
		* or perform a range check on the resulting squared number, after finding it

'''

import sys
import time
import math

timeit = 1
debugv = 0

def main():
	T = int(sys.stdin.readline())
	for case in range(1,T+1):
		doCase(case)

def fair(n):
	digits = str(n)
	for i in range(round(len(digits) / 2)):
		if digits[i] != digits[len(digits)-1-i]:
			return False
	return True

def fairsquare_inverted(n):
	if not fair(n):
		return False
	
	square = n**2
	
	return fair(square)

def doCase(case):
	A, B = [int(n) for n in sys.stdin.readline().split()]
	
	root_A = math.ceil(math.sqrt(A))
	root_B = math.floor(math.sqrt(B))
	
	result = 0
	for n in range(root_A, root_B + 1):
		if fairsquare_inverted(n):
			result += 1
	
	debug("{}\n".format(result))
	sys.stdout.write("Case #{}: {}\n".format(case, result))


def debug(m):
	if debugv:
		sys.stderr.write(m)

if __name__ == '__main__':
	startTime = time.clock()
	main()
	if timeit:
		sys.stderr.write("Completed in {} seconds.\n".format(time.clock() - startTime))

