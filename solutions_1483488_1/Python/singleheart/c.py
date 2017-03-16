#!/usr/bin/python

# C. Recycled Numbers

import sys
import math


f = sys.stdin
T = int(f.readline())

for t in range(1, T+1):
	input = [int(i) for i in f.readline().split()]
	A = input[0]
	B = input[1]

	result = 0

	for i in range(A, B + 1):
		a = str(i)
		l = []
		for j in range(1, len(a)):
			n = int(a[j:]+a[:j])
			if A <= i < n <= B and n not in l:
				result += 1
			l.append(n)

	print "Case #%d: %s" % (t, result)
