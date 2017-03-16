#coding: utf8


s = '''\
4
1? 2?
?2? ??3
? ?
?5 ?0
'''

input = iter(s.splitlines(keepends=True))
import sys
out = sys.stdout
input = open('B-small-attempt0.in')
out   = open('B-small-attempt0.out', 'w')

#input = open('C-large.in')
#out   = open('C-large.out', 'w')

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
	
#solve('t', 'test')	
	
CaseCnt = int(next(input))
for case in range(CaseCnt):
	C,J = next(input).split()
	
	c,j = solve(C,J)
	
	c = str(c).rjust(len(C), '0')
	j = str(j).rjust(len(J), '0')
	
	print('Case #%d:'%(case+1), c,j, file=out)
