
from fractions import Fraction

def solve(fraq):
	bf = bin(fraq.denominator)
	if bf.count("1")>1:
		return None
	for i in xrange(1, 40):
		f = Fraction(1, 2**i)
		if fraq >= f:
			return i
	return None
	

T = int(raw_input())
for t in xrange(1,T+1):
	P,Q = map(int, raw_input().strip().split("/"))
	fraq = Fraction(P, Q)
	gens = solve(fraq)
	if gens is None:
		print "Case #{}: impossible".format(t)
	else:
		print "Case #{}: {}".format(t, gens)

