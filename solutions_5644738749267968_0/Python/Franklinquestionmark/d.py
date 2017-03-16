#!python3

def toint(s):
	'''to a bigger int because floats suck'''
	if '.' not in s:
		ipart = s
		fpart = ''
	else:
		ipart, fpart = s.split('.')
	fpart = fpart.ljust(5,'0')
	return int(ipart+fpart)

def process(cin):
	#$$INPUT$$
	N = cin.int
	
	naomi = cin.lineas(toint)
	ken = cin.lineas(toint)
	
	#$$COMPUT$$
	def solve():
		#optimal: if Ken can score, then he
		#  uses the lowest winning play
		# else, if he can't score, he scores
		#  using the lowest play
		#So to force out his biggest masses,
		#  present your weakest as slightly weaker
		#  than his strongest
		#  and then beat him.
		#Her best score will then be the number
		#  of weights that beat his, in sorted order.
		#So take her best against his worst, and count
		#  winning pairs.
		
		#Deceit:
		#Just the maximal number of weights she has that can beat his
		#Take her biggest weights and go down until there's one she wins
		kiter = iter(sorted(ken, reverse=True))
		# ki = next(kiter)
		deceit = 0
		for ni in sorted(naomi, reverse=True):
			if next(dropwhile(lambda ki: ni<=ki, kiter), None) is None:
				break
			else:
				deceit += 1
		
		#Naomi normal optimal play:
		#???
		#don't know if it matters what order she plays.
		#pretty sure it doesn't.
		#normal optimal play is just like switching roles
		#  except the other side loses ties?
		niter = iter(sorted(naomi, reverse=True))
		# ni = next(niter)
		regular = N
		for ki in sorted(ken, reverse=True):
			if next(dropwhile(lambda ni: ki<=ni, niter), None) is None:
				break
			else:
				regular -= 1
		
		return deceit, regular
	
	#$$OUTPUT$$
	# int int
	#deceit score, regular score
	return ' '.join(map(str,solve())) # i am horrible person



INPUT_STRING = '''4
1
0.5
0.6
2
0.7 0.2
0.8 0.3
3
0.5 0.1 0.9
0.6 0.4 0.3
9
0.186 0.389 0.907 0.832 0.959 0.557 0.300 0.992 0.899
0.916 0.728 0.271 0.520 0.700 0.521 0.215 0.341 0.458'''



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
		
		cin(* 4*[int]) #tuple of four ints
		cin(int, str, int, int)
		cin(* [int]*4 + [str] + 3*[int]) #tuple: 4 ints, str, 3 ints
		cin(int) #int (not tuple)
		cin(int, (int, int)) # ugh but why
	maybe should rename "gin" for "get in" instead, to represent a different idea.
	'''
	def __init__(self, src=stdin):
		if type(src) == str:
			src = src.splitlines()
		self.src = iter(src)
		self.buf = None
	def get(self, typ):
		return typ(next(self))
	def __getattr__(self, typ): #cin.int
		return eval(typ)(next(self))
	
	__getitem__ = get #cin[int]
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
	def __call__(self, typ, *args):
		# if len(args) > 0: #ugh this makes cin(*[int]) work wrong
			return tuple(map(self.get, args))
		# elif callable(typ):
			# return self.get(typ)

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
