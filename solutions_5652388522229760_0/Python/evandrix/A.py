#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

T = int(sys.stdin.readline())
for t in xrange(1,T+1):
		print "Case #%d:"%t,
		N = int(raw_input())
		lookup = [False for _ in xrange(10)]
		last = -1
		i = 1
		while True:
			if N == 0: break
			n = i * N
			digits = set(str(n))
			for digit in digits:
				lookup[int(digit)] = True
			if all(lookup):
				last = n
				break
			i+=1
		print last if all(lookup) else "INSOMNIA"
