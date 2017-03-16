#!/usr/bin/env python
import sys

def solve(input):
	b, m = [int(i) for i in input.split(' ')]
	most = 2**(b-2)
	toRemove = 2**(b-2) - m
	if toRemove < 0:
		return 'IMPOSSIBLE'
	removed = []
	pathsRemoved = 0
	for i in range(1, b-1):
		r = 2**(b-2-i)
		if pathsRemoved + r <= toRemove:
			removed.append((0, i))
			pathsRemoved += r
	matrix = []
	for i in range(b):
		cur = []
		for j in range(i+1):
			cur.append(0)
		for j in range(b-i-1):
			cur.append(1)
		matrix.append(cur)
	for r in removed:
		matrix[r[0]][r[1]] = 0
	result = ['POSSIBLE']
	for m in matrix:
		result.append(''.join(str(i) for i in m))
	return '\n'.join(result)

	

for arg in sys.argv:
    filename = arg
f = open(filename, 'r')
lines = f.read().split('\n')
numCases = int(lines[0])
cases = lines[1:]
for i in range(numCases):
	print 'Case #' + str(i + 1) + ': ' + str(solve(cases[i]))