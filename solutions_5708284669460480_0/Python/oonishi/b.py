#coding: cp932
# 2015 Round1-C Probleb B
input = iter('''
6
7 6 6
BANANAS
MONKEY
2 3 4
AA
AAA
2 1 2
AB
B
6 2 2
GOOGLE
GO
26 11 100
ABCDEFGHIJKLMNOPQRSTUVWXYZ
ROSENCRANTZ
4 3 100
TEST
ABA
'''.splitlines()[1:])
import sys
output = sys.stderr

from ctypes import *
inf = float('inf')
#cdll.c.solve.restype = c_ulonglong
#cdll.c.walk
sys.setrecursionlimit(1500)

filename = ''

filename = r'B-small-attempt0.in'
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
def solve(K,L,S):
	l = len(L)
	for i in range(1,len(L)):
		if L[i:] == L[:len(L)-i]:
			l = i
			break
	else:
		l = len(L)
	print(l)
	
	banana = len(K)//l
	
	
	have = 0
	ex = 0.0
	for x in range(len(K)**S):
		
		s = ''
		for i in range(S):
			s += K[x%len(K)]
			x //= len(K)
			
		cnt = 0
		for i in range(S-len(L)+1):
			if s[i:].startswith(L):
				cnt += 1
		have = max(cnt,have)
		ex += cnt/(len(K)**S)
	
	
	
	return have-ex
		
	#print(E)
	
import time
st = time.time()
caseCnt = int(next(input))
for caseNo in range(caseCnt):
	K,L,S = map(int, next(input).split())
	K = next(input).split()[0]
	L = next(input).split()[0]

	answer = solve(K,L,S)
	print('Case #%d:'%(caseNo+1), answer, file=output)
	
	print(caseNo,time.time()-st)