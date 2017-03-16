#!/usr/bin/python

import sys, random

T = int(sys.stdin.readline().split()[0])

def preprocess(N):
	array = []
	for i in xrange(2*N + 1):
		array.append(['0'] * (2*N + 1))

	steps = []
	for i in xrange(2*N + 1):
		steps.append([0] * (2*N + 1))

	dirs = ['N', 'E', 'S', 'W']
	xPos = [0, 1, 0, -1]
	yPos = [1, 0, -1, 0]

	array[N][N] = ''

	queue = []
	queue.append([N, N])

	while len(queue) > 0:
		i, j = queue.pop(0)
		char = array[i][j]
		z = steps[i][j]

		if char == '0':
			continue

		for k in xrange(4):
			new_i = i + (z+1) * xPos[k]
			new_j = j + (z+1) * yPos[k]

			if new_i < 0 or new_j < 0 or new_i >= 2*N + 1 or new_j >= 2*N + 1:
				continue

			if array[new_i][new_j] == '0':
				array[new_i][new_j] = dirs[k]
				steps[new_i][new_j] = z + 1
				queue.append([new_i, new_j])
	
	return array, steps

def getPathReal(x, y):
	output = ''

	while output == '':
		output = getPath(x,y)

	return output

def getPath(x, y):
	dirs = ['N', 'E', 'S', 'W']
	xPos = [0, 1, 0, -1]
	yPos = [1, 0, -1, 0]

	X = 0
	Y = 0

	output = ''
	for k in xrange(1, 501):
		dir = random.randint(0,3)
		X += k * xPos[dir]
		Y += k * yPos[dir]
		output += dirs[dir]

		if x == X and y == Y:
			return output

	return ''

	x += N
	y += N

	output = ''

	while array[x][y] <> '':
		dir = dirs.index(array[x][y])
		step = steps[x][y]

		output += dirs[dir]
		x -= xPos[dir] * step
		y -= yPos[dir] * step
	
	return output[::-1]

#array, steps = preprocess(0)

def out(rows):
	for z in rows:
		print z

#out(array)
#out(steps)
for i in xrange(T):
	x, y = sys.stdin.readline().split()

	print "Case #{0}: {3}".format(str(i+1), x, y, getPathReal(int(x), int(y)))
