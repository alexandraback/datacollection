#!/usr/bin/python

import numpy

fp = open('b.in')

tests = int(fp.readline()[:-1])
c = 1

while tests > 0:
	items = fp.readline()[:-1].split(' ')
	E = int(items[0])
	R = int(items[1])
	N = int(items[2])
	vals = [int(x) for x in fp.readline()[:-1].split(' ')]
	
	mat = []
	for i in range(0,N+1):
		mat.append([0]*(E+1))
		
	for i in range(0,N):
		for j in range(0,E+1):
			for k in range(0,j+1):
				mat[i+1][min(E,j-k+R)] = max(mat[i+1][min(j-k+R,E)], mat[i][j]+vals[i]*k)
		
	mmax = 0		
	for i in range(0,E+1):
		mmax = max(mmax, mat[N][i])
		
	print "Case #%d: %d" % (c, mmax)
		
		
	c = c + 1
	tests = tests - 1