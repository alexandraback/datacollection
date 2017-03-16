from fractions import Fraction as F

T = int(raw_input())
for t in range(1, T + 1):
	p, q = map(int, raw_input().strip().split('/'))
	print 'Case #%d:' % t,
	_ = F(p, q)
	p, q = _.numerator, _.denominator
	who = None
	for i in range(60):
		if q == (1 << i):
			who = i
			break
	if who is None:
		print 'impossible'
	else:
		while p > 1:
			who -= 1
			p >>= 1
		print who
