'''
Part Elf
'''
from fractions import Fraction as F

if __name__ == '__main__':
	f=open("A-small-attempt0.in")
	Qanc = [2**x for x in range(1,40)]
	nc=int(f.readline())
	for x in xrange(1,nc+1):
		[P,Q] = map(int, f.readline().strip().split('/'))
		frac = F(P, Q)
		P = frac.numerator
		Q = frac.denominator
		if not  Q in Qanc:
			s = 'impossible'
		else:
			r = P / float(Q)
			for i in xrange(1,40):
				if r >= 1.0 / 2**i:
					break
			s = str(i)
		print "Case #%d: %s" % (x, s)
