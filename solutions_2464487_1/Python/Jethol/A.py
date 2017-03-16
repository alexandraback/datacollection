#!/usr/bin/env python2
import sys, os
import math
import gmpy2
# Cases
t = int(sys.stdin.readline())

gmpy2.get_context().precision=150

for case in xrange(t):
	r, t = map(int, sys.stdin.readline().rstrip('\n').split())
	delta = (2*r-1)**2 + 8*t
	result = 0
	if delta < 0:
		result = 0
	else:
		result = int(gmpy2.floor((-(2*r-1)+gmpy2.sqrt(delta))/4))

	print "Case #%d: %d" % (case+1, result)
