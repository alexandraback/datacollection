# Close Match

import fileinput
from itertools import product

def num(s):
	n = 0
	for c in s: n = 10 * n + int(c)
	return n

def rec(c, j, n, i):
	if i == n:
		nc = num(c)
		nj = num(j)
		q = abs(nc - nj)
		return (q, nc, nj)

	z = (10**20, "", "")

	if c[i] == '?' and j[i] == '?':
		for x, y in product(range(0, 10), range(0, 10)):
			c[i] = x
			j[i] = y
			q = rec(c, j, n, i+1)
			if q[0] < z[0]: z = q
			c[i] = '?'
			j[i] = '?'
	elif c[i] == '?':
		for x in range(0, 10):
			c[i] = x
			q = rec(c, j, n, i+1)
			if q[0] < z[0]: z = q
			c[i] = '?'
	elif j[i] == '?':
		for y in range(0, 10):
			j[i] = y
			q = rec(c, j, n, i+1)
			if q[0] < z[0]: z = q
			j[i] = '?'
	else:
		return rec(c, j, n, i+1)
	return z

def solve(c, j):
	n = len(c)
	z = rec(list(c), list(j), n, 0)
	return "%s %s" % (str(z[1]).zfill(n), str(z[2]).zfill(n))

f = fileinput.input()
for t in range(int(f.readline().rstrip())):
	s = f.readline().rstrip().split(' ')
	z = solve(s[0], s[1])
	print('Case #%s: %s' % (t + 1, z))
