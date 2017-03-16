#!/usr/bin/python

import numpy
import sys

fp = open('c.in')

tests = int(fp.readline()[:-1])
c = 1

def calc(products, N, M):
	a = [0]*(6)
	
	for num in products:
		b = [0]*6
		for i in range(2,M+1):
			c = 0
			t = num
			while t % i == 0:
				t = t/i;
				c = c + 1
			if t == 1 and i != 2:
				a[i] = max(a[i], c)
			b[i] = b[i]+c
		a[3] = max(a[3], b[3])
		a[5] = max(a[5], b[5])
#		print b, num

##	print " "
#	print a
	
	ret = []
	
	for i in range(0, 6):
		if a[i] > 0:
			ret.extend([i]*a[i])
			
	while len(ret) < N:
		ret.append(2)
	
	return ret

while tests > 0:
	R, N, M, K = [int(x) for x in fp.readline()[:-1].split(' ')]

#	print R,N,M,K	
	
	print "Case #%d:" % c
	
	for i in range(0, R):
		products = [int(x) for x in fp.readline()[:-1].split(' ')]
		result = calc(products, N, M)
		for i in result:
			sys.stdout.write(str(i))
		print ""
		
	c = c + 1
	tests = tests - 1