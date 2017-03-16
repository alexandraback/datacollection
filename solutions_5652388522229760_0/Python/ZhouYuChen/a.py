#!/usr/bin/env pypy

def sol(n):
	if n == 0:
		return "INSOMNIA"
	a = set()
	for v in xrange(n, 10**9, n):
		a = a.union(str(v))
		if len(a) == 10:
			return v

for t in xrange(1, input()+1):
	print "Case #%d: %s" % (t, sol(input()))
