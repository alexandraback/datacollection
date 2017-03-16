# Less Money, More Problems

import fileinput
from itertools import combinations

def sums(a, v):
	s = set([])
	for l in range(1, len(a) + 1):
		for i in combinations(a, l): 
			x = sum(i)
			if x <= v: s.add(x)
	return s

def fill(a, v, r, n):
	b = set([i for i in range(1, v + 1)]) - a
	for c in combinations(b, n):
		for x in c: a.add(x)
		if sums(a, v) == r: return n
		for x in c: a.remove(x)
	return -1

def solve(d, v, a):
	a = set(a)
	r = set([i for i in range(1, v + 1)])
	for n in range(0, v + 1):
		z = fill(a, v, r, n)
		if z != -1: return z

f = fileinput.input()
for t in range(int(f.readline().rstrip())):
	c, d, v = map(int, f.readline().rstrip().split(' '))
	a = list(map(int, f.readline().rstrip().split(' ')))
	z = solve(d, v, a)
	print('Case #%s: %s' % (t + 1, z))
