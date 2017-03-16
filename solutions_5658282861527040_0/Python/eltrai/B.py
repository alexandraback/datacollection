#!/usr/bin/python
from collections import defaultdict

def readint ():
	return int(input())
def readarray ( f ):
	return map(f, input().split())

def solve(A,B,K):
	stats = defaultdict(int)
	for i in range(A):
		for j in range(B):
			stats[i&j] += 1
	count = 0
	for i in range(K):
		count += stats[i]
	return count
			

cases = readint()
for k in range(cases):
	A,B,K = readarray(int)
	print('Case #' + str(k+1) + ': ' + str(solve(A,B,K)))
