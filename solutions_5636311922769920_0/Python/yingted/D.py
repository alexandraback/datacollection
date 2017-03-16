#!/usr/bin/env python
import gmpy2
import math

def to_int(a, K):
	s = 0
	m = 1
	for x in a:
		s += m * x
		m *= K
	return s

T = int(raw_input())
for t in xrange(1, 1 + T):
	print 'Case #%d:' % t,
	K, C, S = map(int, raw_input().split())
	if S * C < K:
		# Not enough grad students
		print 'IMPOSSIBLE'
	else:
		i = 0
		n = 0
		while i < K:
			n += 1
			a = [min(K - 1, x) for x in xrange(i, i + C)]
			i += C
			print to_int(a, K) + 1,
		assert n <= S
		print
