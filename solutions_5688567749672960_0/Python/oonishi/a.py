#coding: cp932
# 2015 Round1-B Probleb A
input = iter('''
10
90
10
100
1000
1
19
23
101
1001
10001
'''.splitlines()[1:])
import sys
output = sys.stderr

from ctypes import *
#cdll.c.solve.restype = c_ulonglong

inf = float('inf')

filename = r'A-small-attempt7.in'
#filename = r'A-large.in'
input  = open(filename)
output = open(filename[:-3]+'.out', 'w')


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
	
def solve(N):
	M = 1
	c = 1
	for i in range(1,15):
		if N<M*10:
			break
		M *= 10
		c += 10*(i-1)+9
	print(N,M,c)
	if N == M:
		return c
		
	ns = str(N)
	ms = str(M)
	for j,_ in enumerate(ns[:-1]):
		if ms[j] == ns[j]:
			continue
		for i in range(9,int(ms[-1])-1,-1):
			ms2 = ms[:j] + str(i) + ms[j:-1]
			print('a', j,ns,ms2,c)
			if ms2<=ns:
				break
		c += int(ms2[j]) - int(ms[-1]) + 1
		print('b', j ,ns,ms2,c)
		ms = ms2
	print('c',ns,ms,c)
	M = int(ms)
		
	return c + (N-M)
	
import time
st = time.time()
caseCnt = int(next(input))
import os
for caseNo in range(caseCnt):
	N, = map(int, next(input).split())
	#ch = os.fork()
	#print('ch=', ch, os.getpid())
	#if ch != 0:
	#	continue
	answer = solve(N)
	print('Case #%d:'%(caseNo+1), answer, file=output)
	
	print('case %d: %lf'%(caseNo,time.time()-st))