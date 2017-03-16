import sys
import math
import itertools

for testcase in xrange(1, int(sys.stdin.readline())+1):

	r, t = [int(w) for w in sys.stdin.readline().split()]
	a = 2
	b = 2*r - 1
	c = -1 * t
	b_squared = pow(b,2)
	a_c_4 = 8*c
	b_minus_ac = b_squared - a_c_4
	b_ac_sqrt = pow(b_minus_ac, 0.5)
	soln = -1*b + b_ac_sqrt
	best = int(math.floor(soln/4))

	#plug back in to test
	diff = t - (2*best**2+best*(2*r - 1))
	if diff < 0:
		best = best - 1

	print 'Case #%d: %d' % (testcase, best)