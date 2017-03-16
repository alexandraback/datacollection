#!/usr/bin/pypy -E
import sys, os
# Cases
t = int(sys.stdin.readline())

for z in xrange(t):
	result = False
	n = int(sys.stdin.readline())
	D = dict()
	for i in xrange(n):
		D[i + 1] = map(int, sys.stdin.readline().split()[1:])
	for i in xrange(1, n + 1):
		reached = set()
		states = [i]
		while states:
			state = states.pop()
			if state in reached:
				result = True
				break
			reached.add(state)
			states = states + D[state]
	result = "Yes" if result else "No"
	print "Case #%d: %s" % (z+1, result)
