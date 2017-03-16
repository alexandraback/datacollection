#!/usr/bin/python

from math import sqrt,floor

def readint ():
	return int(input())
def readarray ( f ):
	return map(f, input().split())

allofthem = []
def ispal( n ):
	s = str(n)
	l = len(s)
	for i in range(floor(l/2)):
		if s[i] != s[l-i-1]:
			return False
	return True

def getsf( m ):
	global allofthem
	for i in range(floor(sqrt(m))):
		if ispal(i) and ispal(i*i):
			allofthem.append(i*i)

def solve( A, B ):
	global allofthem
	r = 0
	for i in allofthem:
		if i > B:
			return r
		elif i >= A:
			r += 1
	return r

getsf( pow(10, 4) )
cases = readint()
for k in range(cases):
	A, B = readarray(int)
	print('Case #' + str(k+1) + ': ' + str(solve(A, B)))
