# coding: cp932

lines = iter('''
4
3 2
10001
20000
10000
1 2
2 3
5 4
36642
28444
50012
29651
10953
1 4
2 3
2 5
4 5
5 5
36642
28444
50012
29651
10953
1 2
1 4
2 3
2 5
4 5
6 6
10001
10002
10003
10004
10005
10006
1 2
1 6
2 3
2 4
3 5
4 5
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

infile = 'C-small-attempt0.in'
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
	
# def check(a, F):
	# if not a:
		
	
	# for i, f in enumerate(F):
		# if f[0] == a[0] and f[1] == a[1]:
			# if check(a[1:], F[:i] + F[i+1:]):
				# return True
			# else:
				
		# elif f[1] == a[0] and f[0] == a[1]:
			# if check(a[1:], F[:i] + F[i+1:]):
				# return False
	# else:
		# return False
		
# def wark(n, l, Z, G):
	# if l: return []
	
	# #G[l[0]].sort(key=lambda n:Z[n])
	# if l[1] in G[l[0]]:
		# dst = l[1:]
		# while dst:
			# new = wark(l[0], dst, Z, G)
			# if new == dst:
	# else:
		# return l
	
# def walk(n, l, G):
	# if l[1] in G[l[0]]:
		# l = walk(l[0], l[1:], G):
		
	# elif l[1] in G[n]:
		# walk(n, l[1:], G):
	# else:
		# return l[1:]
		
def walk(n, l, G):
	if not l: return []
	while l[0] in G[n]:
		l = walk(l[0], l[1:], G)
		if not l:
			return []
	else:
		return l
		
	

def ascending(l):
	if not l:
		yield []
		return 
	for i, n in enumerate(l):
		for a in ascending(l[:i] + l[i+1:]):
			yield [n] + a
	
def solve(Z,F):
	G = defaultdict(list)
	for f in F:
		G[f[0]] += [f[1]]
		G[f[1]] += [f[0]]
	
	
	l = list(range(len(Z)))
	l.sort(key=lambda n:Z[n])
	for a in ascending(l):
		l = walk(a[0], a[1:], G)
		if not l:
			return ''.join([Z[n] for n in a])
			#a = wark(a[0], a[1:], G, set())
	raise Exception()
	
	
	
#print(solve(13, 1, 3))
caseCnt = int(next(lines))

class C:
	def __init__(me, cnt, typ):
		me.cnt = cnt
		me.typ = typ
	def __repr__(me):
		return 'C(%d,%d)'%(me.cnt, me.typ)

for case in range(1, caseCnt+1):
	N,M = map(int, next(lines).split())
	Z = []
	for _ in range(N):
		Z += [next(lines).split()[0]]
	F = []
	for _ in range(M):
		x, y = map(int, next(lines).split())
		F += [(x-1, y-1)]
	#print(N,M,Z,F)
	
	print('Case #%d:'%(case), solve(Z,F), file=out)

