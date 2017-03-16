#!python3

# INPUT_STRING = '''1
# 1.04601 3.46043 1999.79117
# '''

INPUT_STRING = '''4
30.0 1.0 2.0
30.0 2.0 100.0
30.50000 3.14159 1999.19990
500.0 4.0 2000.0'''

INPUT_STRING = '1 .001 10 100000'

err = .1 ** -7 #uuuugh floats
def process(cin):
	#$$INPUT$$
	c, f, x = cin.line(float)
	# C <=  10,000: cost of farm in cookies
	# F <=     100: cookies per second per farm
	# X <= 100,000: goal
	
	#$$COMPUT$$
	#! todo: check the case c=1 f=100 x=10^5
#	@memoize
	def solve():
		#start at 2 CPS, with 0 cookies
		cps = 2
		
		total = 0
		while c/cps + x/(cps+f) <= x/cps: #buying saves time
			#buy ASAP, leaving us with 0 cookies
			# and thus recursive scenario
			total += c/cps
			cps += f
		#buying a farm is no longer good
		return total + x/cps
	
	#$$OUTPUT$$: number of seconds to reach X.
	return solve()





'$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'
'$                         main                          $'
'$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'

def main(cin, cout):
	T = cin.int
	for i in range(1,T+1):
		print('Case #%d:'%i, process(cin), file=cout)

'$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'
'$                     functions                         $'
'$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'

#https://docs.python.org/3.4/library/bisect.html
def indexof(a, x):
    'Locate the leftmost value exactly equal to x'
    i = bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    raise ValueError

def find_lt(a, x):
    'Find rightmost value less than x'
    i = bisect_left(a, x)
    if i:
        return a[i-1]
    raise ValueError

def find_le(a, x):
    'Find rightmost value less than or equal to x'
    i = bisect_right(a, x)
    if i:
        return a[i-1]
    raise ValueError

def find_gt(a, x):
    'Find leftmost value greater than x'
    i = bisect_right(a, x)
    if i != len(a):
        return a[i]
    raise ValueError

def find_ge(a, x):
    'Find leftmost item greater than or equal to x'
    i = bisect_left(a, x)
    if i != len(a):
        return a[i]

'$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'
'$                         Imports                       $'
'$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'

import sys
from sys import stdin, stdout, stderr, argv
import os

import functools
import functools as ftools
# from functools import *
from functools import (
	partial,
	partial as fixarg,
	lru_cache,
)
memoize = partial(lru_cache, maxsize=None)
import itertools
import itertools as itools
from itertools import *

from operator import *
from random import (
	random,
	randint,
	randrange,
	shuffle,
)
from collections import(
	defaultdict,
	defaultdict as ddict,
	OrderedDict,
	OrderedDict as odict,
)
from queue import(
	PriorityQueue,
	PriorityQueue as pqueue, #min first
)
import re
import numpy
import numpy as np
import math
from math import(
	sqrt,
	log as ln,
	log10,
	log2,
	log2 as lg,
)
import cmath

def ith(i):
	return lambda tupl: tupl[i]

first, second, third = map(ith, range(3))
last = ith(-3)
rest = ith(slice(1,None))

def max_idx(iterable):
	return first(max(enumerate(iterable), key=second))

#import fractions

class istream:
	'''
	Use as:
		cin = istream()
		cin = istream(s)
		cin = istream(open(fname))
		cin.int
		cin.get(int)
		cin.get(float)
		cin.get(str)
		# cin.get(chr) #ugh need to have a better buffer
		cin[int]
		cin.line()
		cin.lineas(int)
		cin.list(int)
		# cin.line(delim)
		# cin.lines()
		# int(cin)?
		next(cin) #next token
	'''
	def __init__(self, src=stdin):
		if type(src) == str:
			src = src.splitlines()
		self.src = iter(src)
		self.buf = None
	def get(self, typ):
		return typ(next(self))
	def __getattr__(self, typ):
		return eval(typ)(next(self))
	
	__getitem__ = get
	__call__ = get
	def __iter__(self): return self
	def line(self, typ=None):
		"""Empty the buffer and return it, or get the next line if it's not empty."""
		if typ is not None:
			return self.lineas(typ)
		if self.buf is not None:
			rv = self.buf
			self.buf = None
			return rv
		else:
			rv = next(self.src).strip('\n')
		return rv #does next work on stdin?
	def __next__(self):
		"""get the next space-delimited token"""
		buf = None
		while buf is None or len(buf.strip()) == 0:
			buf = self.line()
		#split once
		token, *rest = buf.split(maxsplit=1)
		self.buf = rest[0] if rest else None
		return token
	def lineas(self, typ=None):
		if typ is None:
			return self.line()
		return list(map(typ, self.line().split()))
	list = lineas

if __name__ == "__main__":
	if len(argv) > 1:
		infile = argv[1]
		if len(argv) > 2:
			outfile = argv[2]
		else:
			outfile = os.path.splitext(infile)[0]+'.out'
		with open(infile, 'r') as fin:
			with open(outfile, 'w') as fout:
				main(istream(fin), fout)
	elif INPUT_STRING:
		main(cin=istream(INPUT_STRING), cout=stdout)
	else:
		main(cin=istream(stdin), cout=stdout)
