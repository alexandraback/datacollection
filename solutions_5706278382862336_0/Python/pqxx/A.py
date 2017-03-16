import string
import itertools as it
from fractions import Fraction

QS = set()
for i in range(41):
	QS.add(2**i)

def get_rows(lines):
	if lines == 1:
		return map(str, raw_input().split())
	return [map(str, raw_input().split()) for _ in range(lines)]

def get_result(P,Q):
	c = 0
	P = int(P)
	Q = int(Q)
	frac = Fraction(P,Q)
	P = frac.numerator
	Q = frac.denominator
	if Q not in QS:
		return "impossible"
	while P/Q < 1:
		P *= 2
		c += 1
	return c

cases = input()
for i in range(1, cases + 1):
	P,Q = get_rows(1)[0].split('/')
	res = get_result(P,Q)
	print "Case #{0}: {1}".format(i, res)