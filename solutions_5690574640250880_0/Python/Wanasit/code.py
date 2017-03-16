import sys
import math
import itertools


t = int(sys.stdin.readline())
for case in range(1, t+1):
	
	R, C, M = map(int, sys.stdin.readline().split())
	z = 0
	stage = [['.' for j in xrange(C)] for i in xrange(R)]
	
	if R >= 2 and C >= 2:
		R -= 2
		C -= 2
		for cross in xrange(R+C-3):
			max_y = min(cross, R-1)
			max_x = min(cross, C-1)
	
			min_y = max(0, cross - max_x)
			min_x = max_x - (max_y - min_y)
			
			col = max_x
			for row in xrange(min_y, max_y+1):
				if z < M:
					stage[row][col] = '*'
					z += 1
				col -= 1
	
		R += 2
		C += 2

	if z < M:
		r = 0 
		while z+2 < M and r < R - 5:
			stage[r][-1] = stage[r][-2] = '*'
			z += 2
			r += 1

		c = 0 
		while z+2 < M and c < C - 5:
			stage[-1][c] = stage[-2][c] = '*'
			z += 2
			c += 1

	if M - z >= 2 and R >= 2 and C >= 5:
		stage[-1][-5] = stage[-2][-5] = '*'
		z += 2

	if M - z >= 2 and C >= 2 and R >= 5:
		stage[-5][-1] = stage[-5][-2] = '*'
		z += 2

	if M - z >= 1 and R >= 3 and C >= 4:
		stage[-3][-4] = '*'
		z += 1

	if M - z >= 2 and R >= 2 and C >= 4:
		stage[-1][-4] = stage[-2][-4] = '*'
		z += 2

	if M - z >= 1 and R >= 4 and C >= 3:
		stage[-4][-3] = '*'
		z += 1

	if M - z >= 2 and R >= 4 and C >= 2:
		stage[-4][-1] = stage[-4][-2] = '*'
		z += 2

	if M - z >= 1 and R >= 3 and C >= 3:
		stage[-3][-3] = '*'
		z += 1

	if M - z >= 2 and R >= 2 and C >= 3:
		stage[-1][-3] = stage[-2][-3] = '*'
		z += 2

	if M - z >= 2 and R >= 3 and C >= 2:
		stage[-3][-1] = stage[-3][-2] = '*'
		z += 2

	print "Case #{0}:".format(case)
	if R == 1:
		for i in range(M):
			stage[0][i] = '*' 
	elif C == 1:
		for i in range(M):
			stage[i][0] = '*' 
	elif M - z == 3:
		stage[-2][-2] = '*'
		stage[-1][-2] = '*'
		stage[-2][-1] = '*'
	elif M - z > 0:
		#print C, R, M
		print 'Impossible'
		continue

	stage[R-1][C-1] = 'c'
	for row in stage:
		print ''.join(row)