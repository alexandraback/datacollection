import numpy as np
import math
import itertools

def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)

def solve(B, M):
	N = B - 2
	maxMethodCount = (B - 1) + max((B - 3) * (B - 1) / 2, 0)
	index = 0

	if maxMethodCount >= M:
		print "POSSIBLE"
		matrix = [[0 for i in xrange(B)] for j in xrange(B)]
		matrix[0][B - 1] = 1
		count = 1
		flag = False
		if count == M:
			flag = True

		if flag == False:
			for j in xrange(1, B - 1):
				matrix[0][j] = 1
				matrix[j][B - 1] = 1
				count+=1
				if count == M:
					flag = True
					break

		if flag == False:
			for i in xrange(1, B - 1):
				for j in xrange(i + 1, B - 1):
					matrix[i][j] = 1
					count+=1
					if count == M:
						flag = True
						break
					if flag:
						break
				if flag:
						break
		for i in xrange(B):
			for j in xrange(B):
				print matrix[i][j],
			print ''
	else:
		print "IMPOSSIBLE"


T = int(raw_input())
for i in xrange(T):
	tmp = raw_input().split()
	B = int(tmp[0])
	M = int(tmp[1])
	print "Case #%d:" %(i+1),
	solve(B, M)


