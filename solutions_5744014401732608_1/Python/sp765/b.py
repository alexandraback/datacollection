#!/usr/bin/python

import sys
import math

def equal(a,b):
	return abs(a-b) <= 0.000001

def solve(B, M):
	if M > 1 << (B-2): 
		return 'IMPOSSIBLE'

	if B == 2:
		return 'POSSIBLE\n01\n00'

	ans = 'POSSIBLE'

	lst = []
	for i in range(B):
		nlst = []
		for j in range(B):
			nlst.append(0)
		lst.append(nlst)

	for i in range(B):
		row = ''
		for j in range(B-1):
			if j <= i:
				row += '0'
				lst[i][j] = 0
			else:
				row += '1'
				lst[i][j] = 1
		if i > 0:
			if (M & (1 << (i-1)) > 0 or equal(math.log(M,2), B-2)) and i < B-1:
				row += '1'
				lst[i][B-1] = 1
			else:
				row += '0'
				lst[i][B-1] = 0
		else:
			if equal(math.log(M,2), B-2):
				row += '1'
				lst[i][B-1] = 1
			else:
				row += '0'
				lst[i][B-1] = 0

		ans += '\n' + row

	print lst

	return ans

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		#N = int(sys.stdin.readline())
		B, M = map(int, sys.stdin.readline().split())
		print "Case #{}: {}".format(t+1, solve(B, M))
