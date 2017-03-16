#!/usr/bin/env pypy

def flip(x):
	return {'+':'-', '-':'+'}[x]

def sol(s):
	a, r = list(s), 0
	while True:
		while a and a[-1] == '+': a.pop()
		if not a: break
		r += 1
		if a[0] == '-':
			a = map(flip, a[::-1])
			continue
		else:
			for j in xrange(len(a)):
				if a[j] == '+':
					a[j] = '-'
				else:
					break
	return r
for t in xrange(1, input()+1):
	print "Case #%d: %s" % (t, sol(raw_input()))
