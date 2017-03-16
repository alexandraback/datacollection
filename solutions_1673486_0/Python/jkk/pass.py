#!/usr/bin/env python

import sys, math

cases = int(sys.stdin.readline())
for case_no in xrange(1, cases + 1):
	cur, length = [int(val) for val in sys.stdin.readline().strip().split()]
	probs = [math.log(float(val)) for val in sys.stdin.readline().strip().split()]
	ans = length + 2
	if ans > cur + length + 1:
		ans = cur + length + 1
	lprob = 0.0
	for i in xrange(1, cur + 1):
		steps = cur - i
		lprob += probs[i-1]
		prob = math.exp(lprob)
		expectedA = prob * (length - i + steps + 1)
###		print prob, (length - i + steps + 1),
		expectedB = (1 - prob) * (2 * length - i + steps + 2)
###		print (1 - prob), (2 * length - i + steps + 2),
		expected = expectedA + expectedB
###		print expectedA, expectedB, expected
		if expected < ans:
			ans = expected

	print "Case #%d: %f" % (case_no, ans)
	case_no += 1
