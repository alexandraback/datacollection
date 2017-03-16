# coding: cp932

lines = iter('''
5
3 4 2
4 5 2
7 8 5
45 56 35
103 143 88
'''.splitlines(False)[1:])


from math import sqrt
from datetime import datetime
import sys
class Out:
	def __init__(me, f):
		me.file = f
	def write(me, *args):
		sys.stdout.write(*args)
		me.file.write(*args)
out = sys.stdout
#sys.setrecursionlimit(1500)

#from decimal import Decimal, getcontext
#getcontext().prec = 64


date = datetime.now().strftime('%Y%m%d-%H%M%S')

infile = 'B-small-attempt0.in'
#infile = 'C-large-practice.in'
lines = iter(open(infile).read().splitlines(False))
out = Out(open(infile[:-3] + (date + '.answer'), 'w'))



class OffsetedList:
	def __init__(me, size, offset, init=0):
		me.l = [init]*(size+offset)
		me.offset = offset
	def __getitem__(me, index):
		return me.l[index+me.offset]
	def __setitem__(me, index, value):
		me.l[index+me.offset] = value
		
def Choice(n, c):
	if c == 0: return 1
	
	ret = 1
	div = 2
	for i in range(n, n-c, -1):
		ret *= i
		while ret % div == 0 and div <= c:
			ret //= div
			div += 1
	return ret

	
from collections import namedtuple, defaultdict
from itertools import count
from ctypes import*



memcpy = cdll.msvcrt.memcpy
from copy import deepcopy

MAX = float('inf')

import sys
sys.setrecursionlimit(1500)

def equation(a, b, c):
	right = 1.0e+10
	left  = -1.0
	while right-left>1.0e-6:
		t = (right+left)/2
		val = a*t*t + b*t + c
		if val**2 < 1.0e-12:
			return t
		elif val > 0:
			right = t
		else:
			left = t
		#print(t)
	return left
			

		
		
def solve(A,B,K):
	cnt = 0
	for a in range(A):
		for b in range(B):
			if a&b < K:
				cnt += 1
	return cnt

	
	
	
#print(solve(13, 1, 3))
caseCnt = int(next(lines))

class C:
	def __init__(me, cnt, typ):
		me.cnt = cnt
		me.typ = typ
	def __repr__(me):
		return 'C(%d,%d)'%(me.cnt, me.typ)

for case in range(1, caseCnt+1):
	A,B,K = map(int, next(lines).split())
	#import pdb;pdb.set_trace()
	print('Case #%d:'%(case), solve(A,B,K), file=out)

