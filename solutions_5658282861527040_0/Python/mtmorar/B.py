#!/usr/bin/env python

numTests = int(raw_input())

for testNo in xrange(1, numTests + 1):
	a, b, k = map(int, raw_input().split())
	count = 0
	for i in xrange(a):
		for j in xrange(b):
			count += (i & j < k)
	print 'Case #{0}:'.format(testNo), count
