from enum import Enum


class Q(Enum):
	o = 1
	i = 2
	j = 3
	k = 4


class _Q:
	def __init__(self, q, neg=False):
		self.q = q
		self.neg = neg

	def __mul__(self, other):
		neg = False
		if self.q == Q.o:
			p = other.q
		elif other.q == Q.o:
			p = self.q
		elif self.q == other.q:
			p = Q.o
			neg = True
		elif self.q == Q.i:
			if other.q == Q.j:
				p = Q.k
			elif other.q == Q.k:
				p = Q.j
				neg = True
		elif self.q == Q.j:
			if other.q == Q.i:
				p = Q.k
				neg = True
			elif other.q == Q.k:
				p = Q.i
		elif self.q == Q.k:
			if other.q == Q.i:
				p = Q.j
			elif other.q == Q.j:
				p = Q.i
				neg = True
		return _Q(p, self.neg ^ other.neg ^ neg)


to_enum = {
	'1': _Q(Q.o),
	'i': _Q(Q.i),
	'j': _Q(Q.j),
	'k': _Q(Q.k)
}


def pow(s, n):
	if n == 1:
		return s
	if s.q == Q.o:
		return _Q(Q.o, s.neg and (n & 1))
	if n & 1:
		return _Q(s.q, s.neg ^ ((n >> 1) & 1))
	return _Q(Q.o, (n >> 1) & 1)


for t in range(1, int(input()) + 1):
	L, x = map(int, input().split())
	lx = L * x
	s = list(map(lambda x: to_enum[x], input()))
	prod = s[0]
	for i in s[1:]:
		prod *= i
	prods = pow(prod, x)
	x = min(4, x)
	flag = False
	if prods.q == Q.o and prods.neg:
		l = _Q(Q.o)
		for cnt, i in enumerate((s * x)[:-1], 1):
			l *= i
			if l.q == Q.i and not l.neg:
				r = _Q(Q.o)
				for k in reversed((s * x)[cnt - lx:]):
					r = k * r
					if r.q == Q.k and not r.neg:
						flag = True
						break
				break
	print('Case #%d: %s' % (t, 'YES' if flag else 'NO'))