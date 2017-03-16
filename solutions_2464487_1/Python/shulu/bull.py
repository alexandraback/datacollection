import math
from decimal import *

def f (r, t):
	getcontext().prec = 100
	r = Decimal(r)
	t = Decimal(t)
	b = Decimal(2* r - 1)
	return (getcontext().sqrt(b*b+8*t)-b)/4
for i in range(int(raw_input())):
	r,t = map(int, raw_input().split())
	print "Case #%d: %d" % (i+1, int(f(r,t)))
