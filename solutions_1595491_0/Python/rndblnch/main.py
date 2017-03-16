#!/usr/bin/env python
# -*- coding: utf8 -*-

__author__    = "renaud blanch <rndblnch at gmail dot com>"
__copyright__ = "Copyright © 2011–2012 - Renaud Blanch"
__licence__   = "GPLv3 [http://www.gnu.org/licenses/gpl.html]"

from common import nt, ni, nl, line


"""
Dancing with Googlers
"""

def solve(N, S, p, ts):
	i = 0
	for t in sorted(ts, reverse=True):
		a, m = t/3, t % 3
		assert a*3+m == t
		
		if m == 0:
			best = a
			if 0 < best < p:
				best += 1
				S -= 1
		elif m == 1:
			best = a+1
		elif m == 2:
			best = a+1
			if best < p:
				best += 1
				S -= 1			
		if best < p:
			break
		if S < 0:
			break
		i+= 1
	return i

T = ni(); nl()
for X in xrange(T):
	print "Case #%s:" % (X+1),
	N, S, p = ni(), ni(), ni()
	ts = list(line(int))
	assert len(ts) == N
	assert S <= N
	print solve(N, S, p, ts)
