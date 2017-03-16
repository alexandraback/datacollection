#!/usr/bin/python

# A. 

import sys
import math

def fun(A, motes):
	if len(motes) <= 0:
		return 0
	ret = 0
	for i in range(len(motes)):
		if A > motes[i]:
			A += motes[i]
		else:
			ret = 1 + fun(A, motes[i+1:])
			if A > 1:
				k = int(math.log( (motes[i]-1) / float(A-1), 2)) + 1
				ret = min(ret, k + fun((2**k)*A - (2**k) +1 , motes[i:]))
			break

	return ret


f = sys.stdin
T = int(f.readline())

for case in range(1, T+1) :
	A, N = [int(i) for i in f.readline().split()]
	motes = [int(i) for i in f.readline().split()]
	motes.sort()

	ret = fun(A, motes)

	print "Case #%d: %d" % (case, ret)
