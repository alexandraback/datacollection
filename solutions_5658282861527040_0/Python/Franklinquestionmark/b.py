#!python3
#000000001111111111222222222233333333334444444444555555555566666666667777777777
#234567890123456789012345678901234567890123456789012345678901234567890123456789

def process():
	### INPUT ###
	#limits: 10^9
	A, B, K = eats(int, int, int)
	
	
	### COMPUT ###
	#Q: how many numbers less than A and less than B have `&` less than K?
	def setbits(n): #which bits are set
		i = 0
		rv = []
		while n > 0:
			if n&1:
				rv.append(i)
			i += 1
			n >>= 1
		return rv
	def solve():
		def rec(x, y, k):
			if x < y:
				return rec(y, x, k)
			if x > y:
				return 2*[rec(x-1, y, k)]
			if x == 0:
				return 1
			if 1<<x <= k: #all of them
				return 1<<(x+y)
			#assume the next bit is not set
			ans = 3*[rec(x-1, y-1, k)] #three ways to not set it
			#assume the first bit is set
			if 1<<(x-1) <= k:
				ans += [rec(x-1, y-1, k^(1<<(x-1)))] #toggle
			return ans
		
		return list(rec(a, b, K) for a,b in product(setbits(A), setbits(B)))
	def solve():
		bitsA, bitsB = setbits(A), setbits(B)
		
	def solve():
		return sum((a&b) < K
		for a in range(A)
			for b in range(B))
	
	### OUTPUT ###
	return solve()



#########################     busyworks     ###############################

def main():
	T = eat(int)
	for i in range(1, T+1):
		print('Case #%d:'%i, process())

def tokenizer(file=None):
	'''generates tokens from a file source'''
	if file == None:
		from sys import stdin
		file = sys.stdin
	for line in file:
		yield from line.split()

def eat(shape, cin=tokenizer()):
	if callable(shape):
		return shape(next(cin))
	#otherwise it's a sequence
	#return the same kind of sequence
	return type(shape)(eat(typ, cin) for typ in shape)

def eats(*shapes, cin=None):
	if cin is None:
		return eat(shapes)
	return eat(shapes, cin)

#########################     imports     ###############################

import sys
from sys import stdin, stdout, stderr, argv
import os

import functools
import functools as ftools
# from functools import *
from functools import (
	partial,
	partial as bind,
	lru_cache,
	reduce,
)
memoize = bind(lru_cache, maxsize=None)
import itertools
import itertools as itools
from itertools import *

from operator import * #iterable and such
from random import (
	random,
	randint,
	randrange,
	shuffle,
)
import collections
from collections import *
from collections import(
	defaultdict as ddict,
	OrderedDict as odict,
)
import queue
from queue import(
	PriorityQueue,
	PriorityQueue as pqueue, #min first
)
import re
import numpy
import numpy as np
from numpy import(
	array,
)
import math
from math import *
from math import(
	sqrt,
	log as ln,
	log10,
	log2,
	log2 as lg,
)
del log #ugh
import cmath
#import fractions

#########################     main     ###############################
main()
