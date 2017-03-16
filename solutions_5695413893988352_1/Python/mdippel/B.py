#! /usr/bin/env python

import sys, getopt
from collections import defaultdict as dd

#######################
## I/O functions begin
def processInput():
	# yields test cases
	T = int(raw_input())
	for i in range(T):
		C, J = map(str, raw_input().split())
		assert len(C) == len(J)
		yield (C, J)
	return


def writeOutput(results):
	for result in results:
		print result
	return
## I/O functions begin
#######################

def max_remaining(L):
	n = 0
	for c in L:
		n *= 10
		if c == "?":
			n += 9
		else:
			n += int(c)
	return n

def min_remaining(L):
	n = 0
	for c in L:
		n *= 10
		if c == "?":
			n += 0
		else:
			n += int(c)
	return n


def diff(L1, L2):
	x = int("".join(L1))
	y = int("".join(L2))
	return max(x-y, y-x)

def max_min(S1, S2):
	return (S1.replace("?", "9"), S2.replace("?", "0"))

def min_max(S1, S2):
	return (S1.replace("?", "0"), S2.replace("?", "9"))


def optimal(S1, S2):
	if len(S1) == 0:
		return ("", "")
	if S1[0] != "?" and S2[0] != "?":
		if S1[0] > S2[0]:
			return (S1.replace("?", "0"), S2.replace("?", "9"))
		elif S1[0] < S2[0]:
			return (S1.replace("?", "9"), S2.replace("?", "0"))
		elif S1[0] == S2[0]:
			x, y = optimal(S1[1:], S2[1:])
			return (S1[0] + x, S2[0] + y)

	else:
		best_d, best_c, best_j = float('inf'), None, None
		s1_large, s2_min = max_min(S1[1:], S2[1:])
		s1_small, s2_large = min_max(S1[1:], S2[1:])
		if S1[0] == "?" and S2[0] == "?":
			x, y = optimal(S1[1:], S2[1:])
			x = "0" + x
			y = "0" + y
			best_d, best_c, best_j = diff(x,y), x, y

			x = "0" + s1_large
			y = "1" + s2_min
			if diff(x,y) < best_d:
				best_d, best_c, best_j = diff(x,y), x, y

			x = "1" + s1_small
			y = "0" + s2_large
			if diff(x,y) < best_d:
				best_d, best_c, best_j = diff(x,y), x, y

		elif S2[0] != "?":
			a, b, c = str(max(0, int(S2[0]) - 1)), S2[0], str(min(9, int(S2[0]) + 1))
			x = a + s1_large
			y = S2[0] + s2_min
			if diff(x,y) < best_d:
				best_d, best_c, best_j = diff(x,y), x, y

			x, y = optimal(S1[1:], S2[1:])
			x = b + x
			y = b + y
			if diff(x,y) < best_d:
				best_d, best_c, best_j = diff(x,y), x, y

			x = c + s1_small
			y = b + s2_large
			if diff(x,y) < best_d:
				best_d, best_c, best_j = diff(x,y), x, y

		elif S1[0] != "?":
			a, b, c = str(max(0, int(S1[0]) - 1)), S1[0], str(min(9, int(S1[0]) + 1))
			x = b + s1_small
			y = a + s2_large
			if diff(x,y) < best_d:
				best_d, best_c, best_j = diff(x,y), x, y

			x, y = optimal(S1[1:], S2[1:])
			x = b + x
			y = b + y
			if diff(x,y) < best_d:
				best_d, best_c, best_j = diff(x,y), x, y

			x = b + s1_large
			y = c+ s2_min
			if diff(x,y) < best_d:
				best_d, best_c, best_j = diff(x,y), x, y

		return (best_c, best_j)






def ALGORITHM(test_case):
	C, J = test_case
	a, b = optimal(C, J)
	return a + " " + b




	
def basic_test():
	assert ALGORITHM(("1?", "2?")) == "19 20"
	#print ALGORITHM((N, lists))

def runAlgorithm():
	results = []
	for test_case in processInput():
		results.append(ALGORITHM(test_case))

	for i in range(len(results)):
		results[i] = "Case #" + str(i+1) + ": " + results[i] + "\n"

	writeOutput(results)

if __name__ == "__main__":
	basic_test()
	runAlgorithm()
