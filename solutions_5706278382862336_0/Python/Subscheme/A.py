#!/usr/bin/python

from fractions import gcd

def get(f=int):
	return map(f, raw_input().split())

def log2(x):
	c = 0
	while x > 1:
		c += 1
		y = x
		x /= 2
		if x * 2 != y:
			return None
	return c

T, = get()

for case in range(1, T+1):
	s, = get(str)
	P,Q = map(int,s.split('/'))
	g = gcd(Q,P)
	Q /= g
	P /= g
	n = 1
	poss = None

	if log2(Q) is not None:
		for gen in range(1, 40):
			n *= 2
			oth = n - 1
			if P * n >= Q:
				q = Q * n
				p = P * n - Q
				g = gcd(Q,P)
				q /= g
				p /= g
				a = log2(q)
				if a is not None and a <= 40:
					poss = gen
					break


	if poss is None:
		print "Case #%d: impossible" % case
	else:
		print "Case #%d: %d" % (case, poss)

