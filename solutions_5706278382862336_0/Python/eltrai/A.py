#!/usr/bin/python

def readint ():
	return int(input())
def readarray ( f ):
	return map(f, input().split())

def solve(P, Q, A):
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
