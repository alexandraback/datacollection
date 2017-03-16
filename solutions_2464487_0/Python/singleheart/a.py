#!/usr/bin/python

# A. 

import sys
import math


f = sys.stdin
T = int(f.readline())

for case in range(1, T+1) :
	r, t = [int(i) for i in f.readline().split()]

	count = 0
	total = 0
	while True:
		total += (r+1)**2 - r**2
		if total > t: break
		r += 2
		count += 1

	print "Case #%d: %d" % (case, count)
