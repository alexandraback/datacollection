# Brattleship

import fileinput

def miss(r, c, w):
	return r * (c // w)

def hit(c, w):
	if c == w or w == 1: return c
	if c == w + 1: return c
	if w >= c / 2: return w + 1

	return 1 + hit(c - w, w)

def solve(r, c, w):
	return miss(r - 1, c, w) + hit(c, w)

f = fileinput.input()
for t in range(int(f.readline().rstrip())):
	r, c, w = map(int, f.readline().rstrip().split(' '))
	z = solve(r, c, w)
	print('Case #%s: %s' % (t + 1, z))
