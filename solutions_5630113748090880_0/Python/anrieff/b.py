#!/usr/bin/env python

import random

# Contestant: Veselin 'anrieff' Georgiev
# Round: Google Code Jam Qualification 2016
# Task B: Rank and File
# Solution: Observation - count the ocurrences of all digits in all rows/columns. The one that are mentioned odd number of times form the missing row/column, which should be strictly increasing


TC = int(raw_input().strip())

for tc in xrange(1, TC + 1):
	print "Case #%d:" % tc, 
	n = int(raw_input())
	counts = {}
	for i in xrange(2*n - 1):
		line = map(int, raw_input().strip().split())
		for x in line:
			if x not in counts:
				counts[x] = 1
			else:
				counts[x] += 1
	recovered = sorted(filter(lambda x: counts[x] % 2 == 1, counts.keys()))
	print " ".join(map(str, recovered))

	
	
