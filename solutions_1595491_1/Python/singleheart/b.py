#!/usr/bin/python

# B.Dancing With the Googlers 

import sys
import math


def bestResult(n):
	if n % 3 == 0:
		return n / 3
	else:
		return n / 3 + 1

def surprising(n):
	if n == 0:
		return 0
	if n % 3 == 2:
		return n / 3 + 2
	else:
		return n / 3 + 1


f = sys.stdin
T = int(f.readline())

for t in range(1, T+1):
	input = [int(i) for i in f.readline().split()]
	N = input[0]
	S = input[1]
	p = input[2]
	scorelist = input[3:]
	nc = 0
	ns = 0
	for score in scorelist:
		if bestResult(score) >= p:
			nc += 1
		if surprising(score) >= p:
			ns += 1

	result = nc + min(S, ns - nc)

	print "Case #%d: %s" % (t, result)
