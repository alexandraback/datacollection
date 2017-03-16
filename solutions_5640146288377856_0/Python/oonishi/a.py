#coding: cp932
# 2015 Round1-C Probleb A
input = iter('''
5
1 4 2
1 7 7
1 5 1
1 5 2
1 10 8
'''.splitlines()[1:])
import sys
output = sys.stderr

from ctypes import *
inf = float('inf')
#cdll.c.solve.restype = c_ulonglong
#cdll.c.walk
#sys.setrecursionlimit(1500)

filename = ''

filename = r'A-small-attempt5.in'
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
def solve(R,C,W):
	print(R,C,W)
	if W == 1:
		return R*C
		
	n = C//W*(R-1)
	
	#import pdb;pdb.set_trace()
	if 2*W > C:
		d = 2*W-C 
		return n + d + (W-d)*2
	else:
		return n + (C-1)//W + (W-1)*2
	
def solve(R,C,W):
	print(R,C,W)
	if C>=2*W:
		return max(1+solve(R,C-W,W), 1+W)
	elif W==C:
		return W
	else:
		return W+1
	
import time
st = time.time()
caseCnt = int(next(input))
for caseNo in range(caseCnt):
	R,C,W = map(int, next(input).split())
	answer = solve(R,C,W)
	print('Case #%d:'%(caseNo+1), answer, file=output)
	
	print(caseNo,time.time()-st)