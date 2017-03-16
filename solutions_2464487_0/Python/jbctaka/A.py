#!python
# -*- coding: utf-8 -*-

import sys
import math
from decimal import *

def nroot(a):
	oldx = Decimal(0.0)
	x = Decimal(1.0)
	while oldx != x:
		oldx = x
		x = (oldx + a / oldx) / 2
	return x

T = int(sys.stdin.readline().strip())

for index in range(1, T + 1):
	(r, t) = [int(x) for x in sys.stdin.readline().split()]
	
	getcontext().prec = 40
	n = (-(2 * r - 1) + nroot(Decimal((2 * r - 1) ** 2 + 8 * t))) / 4
	print "Case #%d: %d" % (index, int(n))
