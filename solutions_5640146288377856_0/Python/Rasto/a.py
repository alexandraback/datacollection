# Brattleship

import fileinput

def solve(r, c, w):
	if c == w or w == 1: return c
	if c == w + 1: return c

	if w >= c / 2: return w + 1

	if c == 4:
		if w == 2: return 3
	if c == 5:
		if w == 2: return 4
	if c == 6:
		if w == 2: return 4
	if c == 7:
		if w == 2: return 5
		if w == 3: return 5
	if c == 8:
		if w == 2: return 5
		if w == 3: return 5
	if c == 9:
		if w == 2: return 6
		if w == 3: return 5
		if w == 4: return 6
	if c == 10:
		if w == 2: return 6
		if w == 3: return 6
		if w == 4: return 6

f = fileinput.input()
for t in range(int(f.readline().rstrip())):
	r, c, w = map(int, f.readline().rstrip().split(' '))
	z = solve(r, c, w)
	print('Case #%s: %s' % (t + 1, z))
