#!/usr/bin/env python
# -*- coding: utf8 -*-

__author__    = "renaud blanch <rndblnch at gmail dot com>"
__copyright__ = "Copyright © 2011–2012 - Renaud Blanch"
__licence__   = "GPLv3 [http://www.gnu.org/licenses/gpl.html]"

"""
common utils for google code jam contest
"""

import sys

def _tokens(stdin=sys.stdin):
	for line in stdin:
		for token in line.split():
			yield token
		yield StopIteration
_tokens = _tokens()

def nt(): return next(_tokens)
def ni(): return int(nt())
def nl(): assert nt() is StopIteration
def line(t=str):
	for token in _tokens:
		if token is StopIteration:
			raise StopIteration
		yield t(token)
