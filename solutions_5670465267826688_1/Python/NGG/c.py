#!/usr/bin/env python
from sys import stdin
from operator import mul

class Quat(object):
	cmap = {'1': 0, 'i': 1, 'j': 2, 'k': 3}
	mult = [[(0, 1), (1, 1), (2, 1), (3, 1)], [(1, 1), (0, -1), (3, 1), (2, -1)], [(2, 1), (3, -1), (0, -1), (1, 1)], [(3, 1), (2, 1), (1, -1), (0, -1)]]
	powt = [[(0, 1), (0, 1), (0, 1), (0, 1)], [(0, 1), (1, 1), (0, -1), (1, -1)], [(0, 1), (2, 1), (0, -1), (2, -1)], [(0, 1), (3, 1), (0, -1), (3, -1)]]

	def __init__(self, c='1', s=1):
		self.c = Quat.cmap[c] if isinstance(c, basestring) else c
		self.s = s

	def __repr__(self):
		return ('' if self.s == 1 else '-') + '1ijk'[self.c]

	def __mul__(self, other):
		x = Quat.mult[self.c][other.c]
		return Quat(x[0], x[1]*self.s*other.s)

	def __pow__(self, n):
		x = Quat.powt[self.c][n % 4]
		return Quat(x[0], x[1]*(self.s**n))

	def __eq__(self, other):
		return self.c == other.c and self.s == other.s

	def __ne__(self, other):
		return not (self == other)

	def __hash__(self):
		return self.__repr__().__hash__()

tn = int(stdin.readline())
for ti in xrange(tn):
	l, x = map(int, stdin.readline().split())
	sd = stdin.readline()
	s = [Quat(sd[i]) for i in xrange(l)]
	def f():
		m = reduce(mul, s, Quat('1'))
		if m**x != Quat('1', -1): return False

		d = {}
		for i in xrange(4):
			for j in [1, -1]:
				q = Quat(i, j)
				#print i, j, q
				y = None
				for k in xrange(4):
					if (m**k)*q == Quat('i'):
						y = k*l
						break
				d[q] = y
		#print d
		besti = None
		mt = Quat('1')
		for i in xrange(l):
			b = d[mt]
			if b is not None:
				if besti is None or besti > b + i:
					besti = b + i
			mt = mt * s[i]
		#print besti
		if besti is None: return False

		d = {}
		for i in xrange(4):
			for j in [1, -1]:
				q = Quat(i, j)
				y = None
				for k in xrange(4):
					if q*(m**k) == Quat('k'):
						y = k*l
						break
				d[q] = y
		#print d
		bestk = None
		mt = Quat('1')
		for i in xrange(l):
			b = d[mt]
			if b is not None:
				if bestk is None or bestk > b + i:
					bestk = b + i
			mt = s[l - i - 1] * mt
		#print bestk
		if bestk is None: return False
		return besti + bestk < x * l
	print 'Case #{0}:'.format(ti+1), 'YES' if f() else 'NO'
