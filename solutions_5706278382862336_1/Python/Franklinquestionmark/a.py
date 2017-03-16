#!python3
#000000001111111111222222222233333333334444444444555555555566666666667777777777
#234567890123456789012345678901234567890123456789012345678901234567890123456789

class Solved(Exception):
	pass

def gcd(a, b):
	if a == 0:
		return b
	return gcd(b%a, a)

IMPOSSIBLE = 'impossible'

def eprint(*args, **kwargs):
	return print(*args, file=stderr, **kwargs)

def process():
	### INPUT ####
	"""The first line of the input gives the number of test cases, T. T lines follow. Each contains a fraction of the form P/Q, where P and Q are integers. """
	pq = eat(str)
	p, q = map(int, pq.split('/'))
	
	### COMPUT ####
	d = gcd(p, q)
	p, q = p//d, q//d
	eprint(bin(q), bin(p))
	if len(bin(q).strip('0')) != 2:
		return IMPOSSIBLE
	#length of p
	binp = bin(p)
	binq = bin(q)
	return len(binq) - len(binp)
	
	### OUTPUT ####
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

def listmap(fn, *iters):
	return list(map(fn, *iters))

nth = lambda n: lambda x: x[n]
first = nth(0)
second = nth(1)


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
from heapq import *

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
# stderr = open(os.devnull, 'w')

main()


