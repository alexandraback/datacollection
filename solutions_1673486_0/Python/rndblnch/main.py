#!/usr/bin/env python
# -*- coding: utf8 -*-

__author__    = "renaud blanch <rndblnch at gmail dot com>"
__copyright__ = "Copyright © 2011–2012 - Renaud Blanch"
__licence__   = "GPLv3 [http://www.gnu.org/licenses/gpl.html]"

from common import nt, ni, nl, line


"""
Password Problem
"""

def products(*ps):
	r = 1.
	yield r
	for p in ps:
		r *= p
		yield r

def opt_strategy(A, B, ps):
	cum_ps = list(products(*ps))
	scores = []
#	for i in range(A+1): # nb of bsp
#		p = cum_ps[A-i]
#		score = p*(B+2*i+1) + (1.-p)*(2*B+2*i+2)
#		scores.append(score-A)
	scores = [B-A+2*i+1 + (1.-cum_ps[A-i])*(B+1) for i in range(A+1)]
	scores.append(B+2)
	return min(scores)

T = ni(); nl()
for X in xrange(T):
	print "Case #%s:" % (X+1),
	A, B = line(int)
	ps = [p for p in line(float)]
	assert len(ps) == A
	print opt_strategy(A, B, ps)
