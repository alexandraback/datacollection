#!/usr/bin/env pypy
import sys, os
import itertools
# Cases
t = int(sys.stdin.readline())

def solve(einit, efin, imin, imax, E, R, N, Vi):
	if imin == imax:
		return 0
	maxval = max(Vi[imin:imax])
	indexes = [idx for idx in range(imin, imax) if Vi[idx]==maxval]
	for idx in indexes:
		eminafter = max(0, efin - R * (imax - idx))
		emaxbefore = min(E, einit + R*(idx-imin+1))
		#print "imin %d imax %d idx %d min %d max %d" % (imin, imax, idx, eminafter, emaxbefore)
		gain = (emaxbefore - eminafter)*maxval
		gain += solve(einit, emaxbefore, imin, idx, E, R, N, Vi)
		gain += solve(eminafter, efin, idx + 1, imax, E, R, N, Vi)
		return gain


for case in xrange(t):
	E, R, N = map(int, sys.stdin.readline().rstrip('\n').split())
	Vi = map(int, sys.stdin.readline().rstrip('\n').split())
	result = solve(E, 0, 0, N, E, R, N, Vi)

	print "Case #%d: %d" % (case+1, result)
	sys.stdout.flush()
