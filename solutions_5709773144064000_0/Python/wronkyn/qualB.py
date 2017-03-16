#!/usr/bin/python

import sys

def testCase(case, C, F, X):
	time = X/2.0

	n = 1

	while True:
		difference = C/(2 + (n-1.0)*F) + X/(2 + n*F) - X/(2 + (n-1)*F)

		if (difference >= 0.0):
			break

		time += difference
		n += 1

	print "Case #{}: {}".format(case, time)

if __name__ == "__main__":
	testCases = int(sys.stdin.readline())

	for i in range(1, testCases + 1):
		params = [float(k) for k in sys.stdin.readline().split()]
		testCase(i, params[0], params[1], params[2])
		
else:
	print "not main"
