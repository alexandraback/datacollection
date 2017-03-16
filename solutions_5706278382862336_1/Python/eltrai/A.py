#!/usr/bin/python
from fractions import Fraction

def readint ():
	return int(input())
def readarray ( f ):
	return map(f, input().split())

def solve(P1, Q1, A):
	f = Fraction(P1,Q1)
	P = f.numerator
	Q = f.denominator
	if Q not in A:
		return "impossible"
	for i in range(41):
		if P*A[i] >= Q:
			return i
	
	return "error"

A = [2**i for i in range(41)]

cases = readint()
for k in range(cases):
	P,Q = map(int, input().split('/'))
	print('Case #' + str(k+1) + ': ' + str(solve(P, Q, A)))
