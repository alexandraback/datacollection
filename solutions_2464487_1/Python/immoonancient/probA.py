#!/usr/bin/env python

import sys

casen = int(sys.stdin.readline())
for casei in range(casen):
	line = sys.stdin.readline().split()
	r = int(line[0])
	t = int(line[1])
	
	minn = 1
	maxn = t
	while minn < maxn:
		n = ((minn + maxn) >> 1) + 1
		ink = 2 * n * r + 2 * n * (n - 1) + n
		if ink <= t:
			minn = n
		else:
			maxn = n - 1
	
	print('Case #' + str(casei + 1) + ': ' + str(minn))
