#!/usr/bin/python

# C. Recycled Numbers

import sys
import math

def isRecycle(x, y):
	a = str(x)
	b = str(y)
	for i in range(1, len(a)):
		if a[i:]+a[:i] == b:
			return True
	return False


f = sys.stdin
T = int(f.readline())

for t in range(1, T+1):
	input = [int(i) for i in f.readline().split()]
	A = input[0]
	B = input[1]

	result = 0

	for i in range(A, B + 1):
		for j in range(i + 1, B + 1):
			if isRecycle(i, j):
				result += 1

	print "Case #%d: %s" % (t, result)
