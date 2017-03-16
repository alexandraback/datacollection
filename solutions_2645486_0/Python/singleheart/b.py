#!/usr/bin/python

# B. 

import sys
import math


f = sys.stdin
T = int(f.readline())

for case in range(1, T+1) :
	E, R, N = [int(i) for i in f.readline().split()]
	v = [int(i) for i in f.readline().split()]

	ret = 0
	gain = [v[-1] * i for i in range(E+1)]
	newgain = [0 for i in range(E+1)]
	for i in range(2, N+1):
		for j in range(R, E+1):
			maxval = 0
			for k in range(R, j+1):
				val = k * v[-i] + gain[j - k + R]
				maxval = max(maxval, val)
			newgain[j] = maxval
		gain = newgain

	print "Case #%d: %d" % (case, gain[E])
