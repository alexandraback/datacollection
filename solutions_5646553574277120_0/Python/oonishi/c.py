#coding: cp932
# 2015 Round1-C Probleb C
input = iter('''
4
1 2 3
1 2
1 3 6
1 2 5
2 1 3
3
1 6 100
1 5 10 25 50 100
'''.splitlines()[1:])
import sys
output = sys.stderr

from ctypes import *
inf = float('inf')
#cdll.c.solve.restype = c_ulonglong
#cdll.c.walk
sys.setrecursionlimit(1500)

filename = ''

filename = r'C-small-attempt0.in'
#filename = r'A-large-practice (2).in'

if filename:
	input  = open(filename)
	output = open(filename[:-3]+'3.out', 'w')


def bsearch(key, l):
	if l == []: return 0
	if len(l) == 1:
		return 0 if l[0] > key else 1
	m = len(l)//2
	if l[m] > key:
		return bsearch(key, l[:m])
	else:
		return bsearch(key, l[m:])+m

import copy
import itertools
import pickle
import math

def binint(x):
	n = 0
	for i,c in enumerate(x[::-1]):
		if c == '1':
			n |= (1<<i)
	return n

def bitcnt(x):
	r = 0
	for i in range(64):
		r += (x>>i)&1
	return r

			
#def insert(H,h,less):
def insert(H,h):
	right = len(H)
	left  = -1
	while right-left>1:
		#if len(H)>10000:
		#	print(right, left)
		mid = (left+right)//2
		if h.t>H[mid].t:
			right = mid
		else:
			left = mid
	#print('y',left, right,h.t)
	return right
	#H.insert(right,h)
	

import collections
def solve(C,V,D):
	d = set(D)
	
	d.add(1)
	if V == 1:
		return len(d)-len(D)
		
	d.add(2)
	if V == 2:
		return len(d)-len(D)
		
	if V == 3:
		return len(d)-len(D)
		
	
	
	
	
	while 1:
		can = [0]*(V+1)
		can[0] = 1
		for n in d:
			new = can[:]
			for i in range(V+1):
				#print(i,n,can)
				if can[i] == 1 and i+n <= V:
					new[i+n] = 1
			can = new
				
		if can == [1]*(V+1):
			break
			
		print(d,can.index(0))
		print(can)
		d.add(can.index(0))
	
	
	return len(d)-len(D)
		
	#print(E)
	
import time
st = time.time()
caseCnt = int(next(input))
for caseNo in range(caseCnt):
	C,D,V = map(int, next(input).split())
	*D, = map(int, next(input).split())
	answer = solve(C,V,D)
	print('Case #%d:'%(caseNo+1), answer, file=output)
	
	print(caseNo,time.time()-st)