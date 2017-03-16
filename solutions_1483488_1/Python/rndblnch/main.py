#!/usr/bin/env python
# -*- coding: utf8 -*-

__author__    = "renaud blanch <rndblnch at gmail dot com>"
__copyright__ = "Copyright © 2011–2012 - Renaud Blanch"
__licence__   = "GPLv3 [http://www.gnu.org/licenses/gpl.html]"

from common import nt, ni, nl, line


"""
Recycled Numbers
"""

_r = {}
for n in xrange(2000000):
	sn = str(n)
	l = len(sn)
	ms = set(int(sn[i:]+sn[:i]) for i in range(1, l))
	ms = [m for m in ms if n < m]
	_r[n] = ms
	
def recycled(A, B):
	r = 0
	for n in range(A, B):
		r += sum(m <= B for m in _r[n])
	return r
	
T = ni(); nl()
for X in xrange(T):
	print "Case #%s:" % (X+1),
	A, B = line(int)
	print recycled(A, B)
