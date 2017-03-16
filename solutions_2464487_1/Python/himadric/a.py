#!/usr/bin/env python
import sys
import math

T = int(sys.stdin.readline())

def check(n, r):
	return 2*n*n + (2*r-1)*n

for tt in xrange(T):
	n = 0
	r,t = [int(x) for x in sys.stdin.readline().split()]
	b = 2*r-1
	n = int(math.floor((-b + math.sqrt(b*b + 8*t)) / 4))
	if check(n,r) <= t:
		n += 1

 	print "Case #%d: %d" % (tt + 1, n - 1)
