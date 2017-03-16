#!python
# -*- coding: utf-8 -*-

import sys

T = int(sys.stdin.readline().strip())
for index in range(1, T + 1):
	(E, R, N) = [int(x) for x in sys.stdin.readline().split()]
	V = [int(x) for x in sys.stdin.readline().split()]
	
	cur = [0 for x in range(E + 1)]
	for v in V:
		prev = cur[:]
		for i in range(R, len(cur)):
			cur[i] = 0
			for j in range(R, len(prev)):
				if R - (i - j) >= 0:
					cur[i] = max(cur[i], prev[j] + v * (R - (i - j)))
	print "Case #%d: %d" % (index, max(cur))
