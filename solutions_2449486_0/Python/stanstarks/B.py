#!/usr/bin/env python

import sys

t_n = int(sys.stdin.readline())

for t_t in range(1, t_n+1):
	m = []
	[a, b] = map(int, sys.stdin.readline().split())
	for i in range(a):
		m.append(map(int, sys.stdin.readline().split()))
	maxInCol = [-1]*b
	ans = True
	for i in range(a):
		for j in range(b):
			if maxInCol[j] < m[i][j]:
				maxInCol[j] = m[i][j]
	for i in range(a):
		maxInRow = max(m[i])
		for j in range(b):
			if m[i][j] != maxInRow:
				if maxInCol[j] > m[i][j]:
					ans = False
	if ans:
		print("Case #%d: YES" % t_t)
	else:
		print("Case #%d: NO" % t_t)
