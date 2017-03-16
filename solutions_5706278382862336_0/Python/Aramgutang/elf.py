#!/usr/bin/env python

import fractions
import math
import sys
from decimal import Decimal

def is_possible(p, q, depth, max_depth):
	if depth > max_depth:
		return 0
	
	gcd = fractions.gcd(p, q)
	p = p / gcd
	q = q / gcd
	if Decimal(p) / Decimal(q) < Decimal(1) / Decimal(2 ** depth):
		return is_possible(p, q, depth + 1, max_depth)
	
	new_p = p * 2 ** depth - q
	if new_p == 0 or (is_possible(new_p, q, 1, max_depth - depth) and depth != max_depth):
		return depth
	return 0

with open(sys.argv[1]) as f:
	f.next()
	for case_number, data in enumerate(f, 1):
		p, q = map(int, data.strip().split('/'))
		answer = is_possible(p, q, 1, 40) or 'impossible'
		print 'Case #%s: %s' % (case_number, answer)