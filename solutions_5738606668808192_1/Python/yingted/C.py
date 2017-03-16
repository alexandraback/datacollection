#!/usr/bin/env python
import gmpy2
import math

T = int(raw_input())
for t in xrange(1, 1 + T):
	print 'Case #%d:' % t
	N, J = map(int, raw_input().split())
	for i in xrange(2 ** (N - 1) | 1, 2 ** N, 2):
		if J == 0:
			break
		s = bin(i)[2:]
		for b in xrange(2, 11):
			x = int(s, b)
			if gmpy2.is_prime(x):
				break
		else:
			print s,
			for b in xrange(2, 11):
				x = int(s, b)
				for j in xrange(2, min(10000, x - 1)):
					if x % j == 0:
						print j,
						break
			print
			J -= 1
