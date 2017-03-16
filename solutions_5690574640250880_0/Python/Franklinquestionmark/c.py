#!python3

CLICK = 'c'
MINE = '*'
EMPTY = '.'
NO = 'Impossible'

def process(cin):
	#$$INPUT$$
	R, C, M = cin.line(int)
	
	#R: rows <= 50
	#C: cols <= 50
	#M: mines < R*C
	
	#$$COMPUT$$
	if R > C: #make R <= C
		R, C = C, R
		flip = True
	else: flip = False
	
	#$$OUTPUT$$
	solution = solve(R,C,M)
	if solution is None:
		return '\nImpossible'
	if flip:
		solution = transpose(solution)
	ans = '\n'.join(map(''.join, solution))
		#collapse to single line-delimited string
	
	return '\n'+ans

def solve(R,C,M):
	#if a 1xn board, m can be 1 or 2 away from max
	#if on a not-line board, m has to be at least 4 away
	#  because it needs to be one corner surrounded by 3 empties
	#R <= C
	
	safe = R*C - M
	
	'''
	find r, c, q such that
	r*c corner of empty
	and q more cells on another col
	'''
	if R == 1:
		return [CLICK + (safe-1)*EMPTY + M*MINE]
	if safe == 1:
		field = [[MINE]*C for _ in range(R)]
		field[0][0] = CLICK
		return field
	for c in range(2, C+1):
		r = (safe+c-1)//c #box
		if r>R: #too big
			continue
		if r<2: #too small somehow
			continue
		if (r == 2 or c == 2)and r*c > safe: #overspill
			continue
		if r*c == safe:
			field = [[EMPTY for _ in range(c)] for _ in range(r)]
			field[0][0] = CLICK
			return expand(field, R, C)
		if r + c - 5 >= r*c - safe:
			field = [[EMPTY for _ in range(c)] for _ in range(r)]
			field[0][0] = CLICK
			#crawl along the bottom right edge
			mines = r*c - safe
			print('Mines',mines)
			if mines+2 <= c:
				print('Few')
				for i in range(mines):
					field[-1][-i-1] = MINE
			else:
				print('Many')
				
				i, j = r-1, 2
				for _ in range(mines):
					field[i][j] = MINE
					if j == c-1:
						i -= 1
					else:
						j += 1
			return expand(field, R, C)
	return None

def toField(R, C, safe, c):
	field = [[MINE]*C for _ in range(R)]
	for x in range(safe):
		field[x//c][x%c] = EMPTY
	field[0][0] = CLICK
	
	return field

def expand(field, R, C):
	return [''.join(row).ljust(C, MINE) for row in field] + (R - len(field))*[C*MINE]

def transpose(M):
	#2d transpose
	return list(zip(*M))

def brute(R, C, M):
	pass


INPUT_STRING = '''5
5 5 12
5 5 23
3 1 1
2 2 1
4 7 3
10 10 82
'''


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
