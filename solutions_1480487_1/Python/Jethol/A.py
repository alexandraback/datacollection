#!/usr/bin/env python2
import sys, os
from decimal import *
# Cases
t = int(sys.stdin.readline())

for z in xrange(t):
	result = 0
	input = sys.stdin.readline().split()
	n = int(input.pop(0))
	J = map(int, input)
	X = sum(J)
	result = list()
	sJ = sorted(J)
	cstep = min(J)
	cdiff = 0
	nb = 0
	cnb = 0
	cost = 0
	bar = Decimal(0)
	overbar = True
	for i in sJ:
		if i != cstep:
			cdiff = i - cstep
			if (nb + cnb) * cdiff + cost > X:
				bar = cstep + Decimal(X - cost) / Decimal(nb + cnb)
				cost += Decimal(bar-cstep)*(nb+cnb)
				overbar = False
				break
			else:
				cost += (nb + cnb) * cdiff
				cstep = i
				nb += cnb
				cnb = 0
		cnb += 1
	if overbar:
		bar = max(J) + Decimal(X - cost) / (nb + cnb)
	for i in J:
		res = (bar - i) * 100 / X
		if res > 0:
			result.append(res)
		else:
			result.append(Decimal(0))

	print "Case #%d: %s" % (z+1, ' '.join([i.quantize(Decimal('.000001'), rounding=ROUND_HALF_EVEN).to_eng_string()[0:9] for i in result]))
