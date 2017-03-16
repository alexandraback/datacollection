#!/usr/bin/python

import math

T = input()
for t in range(1, T + 1):
	S = raw_input()

	result = ""
	for c in S:
		if c + result < result + c:
			result = result + c
		else:
			result = c + result

	print "Case #%d: %s" % (t, result)
