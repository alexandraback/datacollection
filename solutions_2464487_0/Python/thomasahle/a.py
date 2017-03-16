
def solve(r, t):
	lo = 0
	hi = 1
	while hi*(2*hi+2*r-1) <= t:
		hi *= 2
	while lo+1 != hi:
		c = (lo+hi)//2
		if c*(2*c+2*r-1) <= t:
			lo = c
		else: hi = c
	return lo

import sys
T = int(sys.stdin.readline())
for case in xrange(T):
	r, t = map(int, sys.stdin.readline().split())
	print "Case #%d: %d" % (case+1, solve(r, t))
