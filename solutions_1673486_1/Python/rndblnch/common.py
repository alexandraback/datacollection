#!/usr/bin/env python
# -*- coding: utf8 -*-

__author__    = "renaud blanch <rndblnch at gmail dot com>"
__copyright__ = "Copyright © 2011–2012 - Renaud Blanch"
__licence__   = "GPLv3 [http://www.gnu.org/licenses/gpl.html]"

"""
common utils for google code jam contest
"""


# input parsing ##############################################################

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


# memoization ################################################################

def memoise(func):
	"""meoization
	
	trade space for speed by caching function results
	"""
	results = dict()
	def f(*args):
		if args in results:
			result = results[args]
		else:
			results[args] = result = func(*args)
		return result
	f.__name__ = func.__name__
	f.__doc__  = func.__doc__
	return f
