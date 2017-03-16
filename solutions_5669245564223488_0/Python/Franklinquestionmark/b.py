#!python3
#000000001111111111222222222233333333334444444444555555555566666666667777777777
#234567890123456789012345678901234567890123456789012345678901234567890123456789

class Solved(Exception):
	pass

IMPOSSIBLE = 'impossible'

def eprint(*args, **kwargs):
	# return
	return print(*args, file=stderr, **kwargs)

M = 10**9 + 7

def process():
	eprint()
	
	### INPUT ####
	"""
	 The first line of the input gives the number of test cases, T. T test cases follow. The first line of each test case contains a single integer N, the number of sets of connected cars. The following line contains N strings separated by a single space. Every given string represents a set of connected cars and is composed of lowercase English letters only.
	"""
	N = eat(int)
	ray = eat([str]*N)
	eprint('Input: ', ray)
	
	
	### COMPUT ####
	lets = [sorted(list(set(x))) for x in ray] #set of letters
	
	#hm.
	#for each letter, all cars with that letter must be next to each other.
	#some things are uniletter, so they can be reordered.
	#others start or end with different letters.
	haslet = dict()
	all_lets = sorted(list(set(''.join(ray))))
	
	rv = 1
	fronts = ddict(lambda: None)
	backs = ddict(lambda: None)
	
	#conditions:
	#- either there's only one with that letter or
	#- this letter is not in the middle
	#- the front and back aren't the same letter (impossible with prev condition!)
	#- 'aba' should be impossible
	
	for let in all_lets:
		cur = haslet[let] = [x for x in ray if let in x]
		
		if len(cur) == 1:
			continue #don't need to move things around
		
		pure = [x for x in cur if len(set(x)) == 1]
		unpure = [x for x in cur if len(set(x)) != 1]
		
		#check if front and back
		front = []
		back = []
		for x in unpure:
			if sum(1 for hm in x.split(let) if hm) > 1:
				eprint('INVALID mid:', let, x)
				return 0
			if sum(1 for hm in ('!'+x+'!').split(let) if hm) != 2:
				eprint('INVALID: center impurity', x)
				return 0
			if x[0] != let: #check front
				front.append(x[0])
			if x[-1] != let: #check back
				back.append(x[-1])
		eprint("front/back:", let, front, back, pure)
		if len(front) > 1 or len(back)>1:
		#check that there is only one choice of front and back
			eprint('INVALID not unique front or back')
			return 0
		
		if front and back and front[0] == back[0]:
			#front and back are the same one
			#(and there's more than one with this letter)
			eprint('INVALID front == back')
			return 0
		
		#if there is something in the front
		#if there's something in the back
		#number of ways to permute pure is factorial(len(pure))
		eprint('PURE: ',let, len(pure))
		rv = (rv * (factorial(len(pure))%M))%M
		eprint(rv)
	
	#check for connected sets
	#for each unconnected letter, find where it belongs
	#and add its front and back to that set
	connected = [set(x) for x in ray]
	
	changed = True
	while changed:
		changed = False
		for comp in connected:
			has = [c1 for c1 in connected if c1&comp]
			hasnot = [c1 for c1 in connected if not c1&comp]
			if len(has) > 1:
				changed = True
				#print(hasnot)
				connected = hasnot + [reduce(lambda x, y: x|y, has)]
				break
	
	# for let in all_lets:
		# bah = let
		# if fronts[let] is not None:
			# bah += fronts[let]
		# if backs[let] is not None:
			# bah += backs[let]
		# has, hasnot = [], []
		# for comp in connected:
			# if any(c in comp for c in bah):
				# has.append(comp)
			# else:
				# hasnot.append(comp)
		# connected = hasnot + [''.join(has)]
	
	eprint('connected', connected)
	
	rv = (rv*(factorial(len(connected))%M))%M
		#permute components
	
	
	#number of different ways to connect trains
	#real problem: how many paths through the graph?
	# edges = [list() for _ in range(N)]
		# #edges[i] = j means there is a path from i to j
	# for i, x in enumerate(ray):
		# for j, y in enumerate(ray):
			# if x[-1] == y[0]:
				# edges[i].append(j)
	
	# fronts = ddict(list)
	# backs = ddict(list)
	# for i, x in enumerate(ray):
		# fronts[x[0]].append(i)
		# backs[x[-1]].append(i)
	
	#restriction is "all letters must be next to themselves"
	
	def solve():
		return rv
	
	### OUTPUT ####
	return solve()


#########################     busyworks     ###############################

def main():
	T = eat(int)
	for i in range(1, T+1):
		print('Case #%d:'%i, process())
		# return

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


