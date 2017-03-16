#!/usr/bin/python

# A. Password Problem

import sys


f = sys.stdin
T = int(f.readline())

for t in range(1, T+1):
	input = f.readline().split()
	(A, B) = (int(input[0]), int(input[1]))
	P = [float(i) for i in f.readline().split()]

	if A == 1:
		result = min(B+2, (B * P[0]) + ((2*B + 1) * (1 - P[0])))
	elif A == 2:
		keep = (B-1)*P[0]*P[1] + 2*B*(1 - P[0]*P[1])
		backone = (B+1)*P[0] + (2*B + 2)*(1 - P[0])
		result = min(keep, backone, B+2)
	else:
		keep = (B-2)*P[0]*P[1]*P[2] + 2*B*(1 - P[0]*P[1]*P[2])
		backone = (B+0)*P[0]*P[1] + (2*B + 1)*(1 - P[0]*P[1])
		result = min(keep, backone, B+2)

	print "Case #%d: %f" % (t, result)
