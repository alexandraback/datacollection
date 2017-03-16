#!/usr/bin/python3

def check(p):
	for l in p:
		for t in ('X', 'O'):
			if all(c in (t, 'T') for c in l):
				return '%s won' % t
	return None

def task():
	p = [input() for i in range(4)]

	# horizontal
	r = check(p)
	if r: return r

	# vertical
	r = check(zip(*p))
	if r: return r

	# diagonal
	for t in ('X', 'O'):
		if all(p[i][i] in (t, 'T') for i in range(4)):
			return '%s won' % t
		if all(p[i][3 - i] in (t, 'T') for i in range(4)):
			return '%s won' % t

	if any(any(c == '.' for c in l) for l in p):
		return 'Game has not completed'
	return 'Draw'

for test in range(int(input())):
	if test != 0: input()
	print('Case #%d:' % (test + 1), task())
