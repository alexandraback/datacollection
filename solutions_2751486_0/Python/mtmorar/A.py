#!/usr/bin/env python

import sys

numTests = int(raw_input())

for test in xrange(1, numTests + 1):
	s, n = raw_input().split()
	n = int(n)
	s = ''.join('0' if c in 'aeiou' else '1' for c in s)
	#print s
	count = 0
	for start in xrange(len(s)):
		for end in xrange(start + n, len(s) + 1):
			if s.count('1' * n, start, end) > 0:
				count += 1
	print 'Case #{0}: {1}'.format(test, count)
