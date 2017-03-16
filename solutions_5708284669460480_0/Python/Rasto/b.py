# Typewriter Monkey

import fileinput
from itertools import product
from collections import defaultdict

def count(s, t):
	c = i = 0
	while True:
		i = s.find(t, i) + 1
		if i > 0:
			c += 1
		else:
			return c

def solve(k, t, n):
	if set(t) - set(k): return 0

	m = defaultdict(int)
	l = 0
	for c in product(k, repeat=n):
		m[''.join(c)] += 1
		l += 1

	z = 0
	r = 0

	for s in m:
		c = count(s, t)
		r += c * m[s] / l
		z = max(z, c)
	return z - r

f = fileinput.input()
for t in range(int(f.readline().rstrip())):
	k, l, n = map(int, f.readline().rstrip().split(' '))
	k = f.readline().rstrip()
	l = f.readline().rstrip()
	z = solve(k, l, n)
	print('Case #%s: %s' % (t + 1, z))
