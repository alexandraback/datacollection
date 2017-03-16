#!/usr/bin/python

import sys

lines = sys.stdin.read().split('\n')
ntask = int(lines[0])
lines = lines[1:]
for task in range(0, ntask):
	line = lines[task].split()
	n = int(line[0])
	line = line[1:]
	data = []
	for x in line:
		data.append(int(x))
	s = 0.0
	for i in range(0, n):
		s = s + data[i]
	ret = ''
	for i in range(0, n):
		lower = 0.0
		upper = 1.0
		while (upper - lower > 1e-10):
			mid = (lower + upper) / 2
			bound = data[i] + s * mid
			cost = 0
			for j in range(0, n):
				if data[j] < bound:
					cost = cost + (bound - data[j]) / s
			if (cost > 1):
				upper = mid
			else:
				lower = mid
		ret = ret + ' ' + repr(lower * 100)
	print('Case #{0}:'.format(task + 1) + ret)

