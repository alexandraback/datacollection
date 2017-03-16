#!/usr/bin/env python

import sys
import random

numTests = int(raw_input())
#numTests = 100

for test in xrange(1, numTests + 1):
	x, y = map(int, raw_input().split())
	#x = random.randint(-100, 100)
	#y = random.randint(-100, 100)
	x0, y0 = 0, 0
	solution = ''
	if x0 < x:
		solution += (x - x0) * 'WE'
	elif x0 > x:
		solution += (x0 - x) * 'EW'
	if y0 < y:
		solution += (y - y0) * 'SN'
	elif y0 > y:
		solution += (y0 - y) * 'NS'
	assert len(solution) < 500
	print 'Case #{0}: {1}'.format(test, solution)
