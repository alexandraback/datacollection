# coding='utf-8'

import os, sys

sys.stdin = open('C-small-attempt0.in')
sys.stdout = open('C-small-attempt0.out', 'w')

complist = '1ijki1kjjk1ikji1'
symlist = '11111-1-1--111--'
comp = dict(zip([x+y for x in '1ijk' for y in '1ijk'], complist))
symp = dict(zip([x+y for x in '1ijk' for y in '1ijk'], [-1 if x == '-' else 1 for x in symlist]))

def mult(x, y, order=1):
	neg = (-1 if x[0] == '-' else 1) * (-1 if y[0] == '-' else 1)
	x, y = x.lstrip('-'), y.lstrip('-')
	sxy = x + y if order == 1 else y + x
	xy = comp[sxy]
	neg = neg * symp[sxy]
	if neg < 0: xy = '-' + xy
	return xy

def QuickPow(a, b):
	if b == 0: return '1'
	if b == 1: return a
	z = QuickPow(a, b // 2)
	z = mult(z, z)
	if b % 2 == 1: z = mult(z, a)
	return z

def FindFirst(P, X, obj, order = 1):
	ret = '1'
	for i in range(X):
		for k, x in enumerate(P):
			ret = mult(ret, x, order)
			if ret == obj: return i * len(P) + k + 1
		if i > 16: break
	return -1

def Work():
	L, X = map(int, input().split())
	P = input()
	ret = '1'
	for x in P: ret = mult(ret, x)
	allprod = QuickPow(ret, X)
	if allprod != '-1': return False
	pp = FindFirst(P, X, 'i', 1)
	if pp == -1: return False
	qq = FindFirst(list(reversed(P)), X, 'k', -1)
	if qq == -1: return False
	if pp + qq >= len(P) * X: return False
	return True

if __name__ == '__main__':
	T = int(input())
	for i in range(T): 
		ans = 'YES' if Work() else 'NO'
		print('Case #%d: %s' % (i+1, ans))
