#!/usr/bin/python

pascal = []
for i in xrange(2001):
	pascal.append([0] * (i+1))

	pascal[i][0] = 1
	pascal[i][i] = 1

	for j in xrange(1,i):
		pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]

def doit(diamonds, x, y):
	level = (abs(x) + y)/2
	prereq = (level * (level + 1))/2
	height = y
	remaining = diamonds - prereq

	if remaining < 0:
		return 0.0
	if remaining >= 1 + 4*level:
		return 1.0
	if height == 2*level:
		return 0.0
	
	num_valid = 0.0

	#print "height: " + str(height) + "remaining: " + str(remaining)
	for i in xrange(height + 1, remaining + 1):
		num_valid += pascal[remaining][i]
	
	return num_valid / pow(2, remaining)

with open("B-small-0.in", 'r') as f:
	num = int(f.readline().split()[0])

	#[:w print num

	for i in xrange(num):
		line = f.readline().split()
		diamonds = int(line[0])
		posX = int(line[1])
		posY = int(line[2])

		#print "case: " + str(i+1) + " diamonds: " + str(diamonds) + " x: " + str(posX) + " y: " + str(posY)
		print "Case #" + str(i+1) + ": " + str(doit(diamonds, posX, posY))
