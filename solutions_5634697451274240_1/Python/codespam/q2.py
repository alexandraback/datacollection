#!/usr/bin/env pypy

import sys


def flip(s, p):
	assert p
	return [not x for x in s[:p][::-1]] + s[p:]

def gs(s):
	n = 0
	l = None
	for c in s:
		if l is None or l != c:
			l = c
			n += 1
	return n

d = [[c == '+' for c in l.strip()] for l in sys.stdin.readlines()[1:]]

for i, c in enumerate(d):
	print 'Case #%d:' % (i + 1),

	n = 0
	while not all(c):
		#print n, c, gs(c)

		mgs = None
		mcc = None
		mx = None
		for x in range(1, len(c) + 1):
			cc = flip(c, x)
			#print 'flip %d gives gs %d' % (x, gs(cc))
			if all(cc):
				mcc = cc
				mx = x
				break
			g = gs(cc)
			if mgs is None or g < mgs:
				mgs = g
				mcc = cc
				mx = x
		#print 'flip %r' % mx

		c = mcc

		n += 1

	print n
