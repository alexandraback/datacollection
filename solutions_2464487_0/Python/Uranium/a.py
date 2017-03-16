from decimal import *
import math

getcontext().prec = 128  # should be good enough

T = int(raw_input().rstrip())
for case in xrange(1, T+1):
	r, t = [Decimal(x) for x in raw_input().rstrip().split()]
	n = Decimal(0.25) * ((4*r*r - 4*r + 8*t + 1).sqrt() - 2*r + 1)
	print "Case #%d: %d" % (case, n)
