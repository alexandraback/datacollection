#! /usr/bin/env python

import sys, getopt
from collections import defaultdict as dd

#######################
## I/O functions begin
def processInput():
	# yields test cases
	T = int(raw_input())
	for i in range(T):
		S = str(raw_input())
		yield S
	return


def writeOutput(results):
	for result in results:
		print result
	return
## I/O functions begin
#######################

D = {}
D[0] = "ZERO"
D[1] = "ONE"
D[2] = "TWO"
D[3] = "THREE"
D[4] = "FOUR"
D[5] = "FIVE"
D[6] = "SIX"
D[7] = "SEVEN"
D[8] = "EIGHT"
D[9] = "NINE"

def ALGORITHM(test_case):
	S = test_case
	count = dd(lambda: 0)
	for c in S:
		count[c] += 1
	#print S
	# remove all ZERO (Z), TWO (W), FOUR (U), SIX (X), EIGHT (G)
	nums = []
	while count['Z'] > 0:
		nums.append(0)
		for c in D[0]:
			count[c] -= 1
	while count['U'] > 0:
		nums.append(4)
		for c in D[4]:
			count[c] -= 1
	while count['X'] > 0:
		nums.append(6)
		for c in D[6]:
			count[c] -= 1
	while count['G'] > 0:
		nums.append(8)
		for c in D[8]:
			count[c] -= 1
	while count['W'] > 0:
		nums.append(2)
		for c in D[2]:
			count[c] -= 1
	while count['O'] > 0:
		nums.append(1)
		for c in D[1]:
			count[c] -= 1
	for (x,n) in [('F', 5), ('V', 7), ('N',9),  ('T', 3) ]:
		while count[x] > 0:
			nums.append(n)
			for c in D[n]:
				count[c] -= 1

	# we have left 3, 5, 7, 9
	# THREE
	# FIVE
	# SEVEN
	# NINE
	nums.sort()
	#print " ".join(map(lambda x: D[x], nums))
	return "".join(map(str, nums))


	
def basic_test():
	ar = ["OZONETOWER",
"WEIGHFOXTOURIST",
"OURNEONFOE",
"ETHER"]
	assert map(ALGORITHM, ar) == ["012", "2468", "114", "3"]
	import random
	for x in D:
		S = list(D[x] * 200)
		random.shuffle(S)
		S = "".join(S)
		assert ALGORITHM(S) == str(x) * 200, S + " " + ALGORITHM(S)

	for i in range(200):
		x = random.randint(10**20, 10**21)
		ans = list(str(x))
		ans.sort()
		ans = "".join(ans)

		chal = map(lambda x: D[int(x)], list(ans))
		random.shuffle(chal)
		chal = "".join(chal)
		assert ALGORITHM(chal) == ans

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
