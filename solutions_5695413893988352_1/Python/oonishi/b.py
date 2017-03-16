#coding: utf8


s = '''\
4
?5 10
1? 2?
?2? ??3
? ?
?5 ?0
'''

input = iter(s.splitlines(keepends=True))
import sys
out = sys.stdout
#input = open('B-small-attempt0.in')
#out   = open('B-small-attempt1.out', 'w')

input = open('B-large.in')
out   = open('B-large.out', 'w')

#input = open('B-large.in')
#out   = open('B-large.out', 'w')
#input = open('D-large-practice.in')
#out   = open('D-large-practice.out', 'w')



from itertools import combinations, permutations, combinations_with_replacement, product
from collections import defaultdict
from copy import deepcopy


def solve(C,J,d):
	if C=='' and J=='':
		return '', ''
		
	if C[0] != '?' and J[0] != '?':
		d = int(C[0])-int(J[0]) + d*10
		c,j  = solve(C[1:], J[1:], d)
		return C[0] + c, J[0] + j
	
	if d == 0:
		if C[0] == '?' and J[0] == '?':
			c,j  = solve(C[1:], J[1:], d*10)
			return '0' + c, '0' + j
		elif C[0] == '?':
			c,j  = solve(C[1:], J[1:], d*10)
			return J[0] + c, J[0] + j
		elif J[0] == '?':
			c,j  = solve(C[1:], J[1:], d*10)
			return C[0] + c, C[0] + j
		else:
			raise
	elif d > 0:
		if C[0] == '?' and J[0] == '?':
			diff = min(d,9)
			c,j  = solve(C[1:], J[1:], d)
			return '0' + c, '1' + j
		elif C[0] == '?':
			c,j  = solve(C[1:], J[1:], d)
			return J[0] + c, J[0] + j
		elif J[0] == '?':
			c,j  = solve(C[1:], J[1:], d)
			return C[0] + c, C[0] + j
		else:
			raise
		
			
def it(s):
	for i in range(10):
		if s[0] != '?' and int(s[0]) != i:
			continue
		for j in range(10):
			if s[1] != '?' and int(s[1]) != j:
				continue
			for k in range(10):
				if s[2] != '?' and int(s[2]) != k:
					continue
				yield i*100 + j*10 + k
			
			
def solve(C,J):
	length = max(len(C),len(J))
	C = C.rjust(3, '0')
	J = J.rjust(3, '0')
	
	res = [99999, 999999, 999999]
	for c in it(C):
		for j in it(J):
			diff = abs(c-j)
			if res[0] > diff:
				res = [diff, c, j]
				
			elif res[0] == diff and res[1] > c:
				res = [diff, c, j]
			elif res[0] == diff and res[1] == c and res[2] > j:
				res = [diff, c, j]
			#print(res)
	return res[1:]
	
def solve(C,J,d):
	if C=='' and J=='':
		return '', ''
		
	if C[0] != '?' and J[0] != '?':
		d = int(C[0])-int(J[0]) + d*10
		c,j  = solve(C[1:], J[1:], d)
		return C[0] + c, J[0] + j
		
		
	if d == 0:
		if C[0] == '?' and J[0] == '?':
			c,j  = solve(C[1:], J[1:], 0)
			c0,j0 = '0' + c, '0' + j
			c,j  = solve(C[1:], J[1:], 10)
			c1,j1 = '1' + c, '0' + j
			c,j  = solve(C[1:], J[1:], -10)
			c2,j2 = '0' + c, '1' + j
			
			d0 = abs(int(c0)-int(j0))
			d1 = abs(int(c1)-int(j1))
			d2 = abs(int(c2)-int(j2))
			d,c,j = min([(d0,c0,j0),(d1,c1,j1),(d2,c2,j2)])
			#if d2 < d0 and d2 < d1:
			#	return c2,j2
			#elif d1 < d0:
			#	return c1,j1
			#else:
			#	return c0,j0
			return c,j
		elif C[0] == '?':
			#c,j  = solve(C[1:], J[1:], 0)
			#return J[0] + c, J[0] + j
			
			c,j  = solve(C[1:], J[1:], 0)
			c0,j0 = J[0] + c, J[0] + j
			
			c1,j1 = c0,j0
			if J[0] != '9':
				c,j  = solve(C[1:], J[1:], 10)
				c1,j1 = str(int(J[0])+1) + c, J[0] + j
			
			c2,j2 = c0,j0
			if J[0] != '0':	
				c,j  = solve(C[1:], J[1:], -10)
				c2,j2 = str(int(J[0])-1) + c, J[0] + j
			
			d0 = abs(int(c0)-int(j0))
			d1 = abs(int(c1)-int(j1))
			d2 = abs(int(c2)-int(j2))
			d,c,j = min([(d0,c0,j0),(d1,c1,j1),(d2,c2,j2)])
			#if d2 < d0 and d2 < d1:
			#	return c2,j2
			#elif d1 < d0:
			#	return c1,j1
			#else:
			#	return c0,j0
			return c,j
		elif J[0] == '?':
			#c,j  = solve(C[1:], J[1:], 0)
			#return C[0] + c, C[0] + j
			c,j  = solve(C[1:], J[1:], 0)
			c0,j0 = C[0] + c, C[0] + j
			
			c1,j1 = c0,j0
			if C[0] != '0':
				c,j  = solve(C[1:], J[1:], 10)
				c1,j1 = C[0] + c, str(int(C[0])-1) + j
			
			c2,j2 = c0,j0
			if C[0] != '9':	
				c,j  = solve(C[1:], J[1:], -10)
				c2,j2 = C[0] + c, str(int(C[0])+1) + j
			
			d0 = abs(int(c0)-int(j0))
			d1 = abs(int(c1)-int(j1))
			d2 = abs(int(c2)-int(j2))
			
			d,c,j = min([(d0,c0,j0),(d1,c1,j1),(d2,c2,j2)])
			#if d2 < d0 and d2 < d1:
			#	return c2,j2
			#elif d1 < d0:
			#	return c1,j1
			#else:
			#	return c0,j0
			return c,j
		else:
			raise
	elif d > 0:
		if C[0] == '?' and J[0] == '?':
			c,j  = solve(C[1:], J[1:], d*10-9)
			return '0' + c, '9' + j
		elif C[0] == '?':
			x = int(J[0])
			c,j  = solve(C[1:], J[1:], d*10 - x)
			return '0' + c, J[0] + j
		elif J[0] == '?':
			x = int(C[0])
			c,j  = solve(C[1:], J[1:], d*10-(9-x))
			return C[0] + c, '9' + j
		else:
			raise
	elif d < 0:
		if C[0] == '?' and J[0] == '?':
			c,j  = solve(C[1:], J[1:], d*10+9)
			return '9' + c, '0' + j
		elif C[0] == '?':
			x = int(J[0])
			c,j  = solve(C[1:], J[1:], d*10 + 9 - x)
			return '9' + c, J[0] + j
		elif J[0] == '?':
			x = int(C[0])
			c,j  = solve(C[1:], J[1:], d*10+x)
			return C[0] + c, '0' + j
		else:
			raise
	
		
	
#solve('t', 'test')	
	
CaseCnt = int(next(input))
for case in range(CaseCnt):
	C,J = next(input).split()

	#import pdb;pdb.set_trace()
	c,j = solve(C,J,0)
	
	#c = str(c).rjust(len(C), '0')
	#j = str(j).rjust(len(J), '0')
	
	print('Case #%d:'%(case+1), c,j, file=out)
