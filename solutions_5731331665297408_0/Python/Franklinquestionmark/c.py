#!python3
#000000001111111111222222222233333333334444444444555555555566666666667777777777
#234567890123456789012345678901234567890123456789012345678901234567890123456789

class Solved(Exception):
	pass

def process():
	### INPUT ###
	"""
	Each test case starts with a single line containing two integers: the number of cities N and the number of possible bidirectional flights M.

N lines then follow, with the i-th line containing the 5-digit zip code of the i-th city. No ZIP code will have leading zeros and all ZIP codes in each test case will be distinct.

M lines then follow, each containing two integers i and j (1 = i < j = N) indicating that a bidirectional flight exists between the i-th city and the j-th city. All flights will be distinct within each test case.

It is guaranteed that you can visit every city following the rules above. 
"""
	N, M = eats(int, int)
	zipcodes = eat(N*[str])
	int1 = lambda x: int(x) - 1
	edgelist = eat(M*[(int1, int1)])
	
	### COMPUT ###
	iperm = listmap(first, sorted(enumerate(zipcodes), key=second))
		#the inverse permutation
	perm = listmap(first, sorted(enumerate(iperm), key=second))
		#the permutation (rankings of the zips)
	edges = [[] for _ in range(N)]
	for i,j in edgelist:
		edges[i].append(j)
		edges[j].append(i)
	for adjs in edges:
		adjs.sort(key=lambda x: zipcodes[x])
	ans = None
	def solve(this, visited):
		#alg:
		#greedy. try the smallest next city possible
		#For each unvisited child (in sorted order),
		#   attempt a visit.
		#   If success, attempt another visit.
		nonlocal ans
		
		if len(visited) == N:
			ans = visited
			raise Solved
		
		unvisited = (x for x in edges[this] if x not in visited)
		
		for child in unvisited:
			#try each child in order
			visited0 = visited + [child]
			for visited1 in solve(child, visited0): #visit from the child
				for visited2 in solve(this, visited1): #visit from here
					yield visited2
		yield visited
		raise ValueError
	### OUTPUT ###
	try:
		[None for n in iperm for _ in solve(n, [n])]
	except Solved:
		return ''.join(zipcodes[n] for n in ans)


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
