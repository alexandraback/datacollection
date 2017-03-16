import fractions

filename = 'elves-large'

with open(filename + '.in') as F, open(filename + '.out', 'w') as O:
	cases = int(F.readline())
	for case in xrange(cases):
		p, q = (int(x) for x in F.readline().split('/'))
		P = fractions.Fraction(p, q)
		N = fractions.Fraction(1, 1)
		n = 0

		for g in xrange(1,40):
			N = N/2

			if N <= P:
				R = P - N
				if 2**40 % R.denominator == 0:
					n = g
					break

		if n != 0:
			O.write('Case #%d: %d\n' % (case + 1, n))
		else:
			O.write('Case #%d: impossible\n' % (case + 1))




