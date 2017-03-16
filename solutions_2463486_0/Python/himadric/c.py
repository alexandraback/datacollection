#!/usr/bin/env python
import sys
import math

T = int(sys.stdin.readline())

def ispalin(n):
	s = str(n)
	if s == s[::-1]:
		return True
	else:
		return False
for tt in xrange(T):
	A, B = [int(x) for x in sys.stdin.readline().split()]
	cnt = 0
	x = int(math.sqrt(A))
	y = x*x
	while y <= B:
		if y >= A and ispalin(x) and ispalin(y):
			cnt += 1
		x += 1
		y = x*x
 	print "Case #%d: %d" % (tt + 1, cnt)
	