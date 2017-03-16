#!/usr/bin/env python
# -*- coding: utf8 -*-

__author__    = "renaud blanch <rndblnch at gmail dot com>"
__copyright__ = "Copyright © 2011–2012 - Renaud Blanch"
__licence__   = "GPLv3 [http://www.gnu.org/licenses/gpl.html]"

from common import nt, ni, nl, line


"""
Kingdom Rush
"""


def two_stars(N, asbs):
	stars = 0
	count = 0
	As, Bs = zip(*asbs)
	As_done = [False for _ in As]
	Bs_done = [False for _ in Bs]
	while True:
		old_Bs_done = None
		while old_Bs_done != Bs_done:
			old_Bs_done = list(Bs_done)
			for i, b in enumerate(Bs):
				if b <= stars and not Bs_done[i]:
					count += 1
					stars += 1 if As_done[i] else 2
					Bs_done[i] = True
					As_done[i] = True
		if stars >= 2*N:
			break
		for i, a in enumerate(As):
			if a <= stars and not As_done[i]:
				count += 1
				stars += 1
				As_done[i] = True
				break
		else:
			return "Too Bad"
	return count
	

T = ni(); nl()
for X in xrange(T):
	print "Case #%s:" % (X+1),
	N = ni(); nl()
	asbs = [tuple(line(int)) for _ in xrange(N)]
	assert len(asbs) == N
	print two_stars(N, asbs)
