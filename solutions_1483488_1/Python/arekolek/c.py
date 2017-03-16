#!/usr/bin/python

from sets import ImmutableSet

T = input()

for case in xrange(1,T+1):
	result = set()
	a, b = (int(s) for s in raw_input().split())
	for k in xrange(a, b+1):
		n = str(k)
		for i in xrange(1, len(n)):
			shift = int(n[i:] + n[:i])
			if k!=shift and  a <= shift <= b:
				result.add(ImmutableSet((k,shift)))
	print 'Case #{0}: {1}'.format(case, len(result))
