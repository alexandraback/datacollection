#!/usr/bin/python

import numpy
import sys
import random

fp = open('c.in')

tests = int(fp.readline()[:-1])
c = 1

def calc(products, N, M):
	a = [0]*(9)
	probs = [0]*(9)
	
	for num in products:
		b = [0]*9
		for i in range(2,M+1):
			c = 0
			t = num
			while t % i == 0:
				t = t/i;
				c = c + 1
			if t == 1 and i != 2 and i != 4 and i != 6 and i != 8:
				a[i] = max(a[i], c)
			b[i] = b[i]+c
		a[7] = max(a[7], b[7])
		a[5] = max(a[5], b[5])
		
		ss = 0
		for i in b:
			ss = ss + i
		
		if ss > 0:
			for i in range(0,9):
				probs[i] = probs[i] + b[i]/float(ss)
		
#		print b, num

#	print " "
#	print a
	
	psum = 0
	for i in probs:
		psum = psum + i
		
	for i in range(0,9):
		probs[i] = probs[i] / psum
	
#	print probs
	
	ret = []
	
	for i in range(0, 9):
		if a[i] > 0:
			ret.extend([i]*a[i])
			
	while len(ret) < N:
		rnum = random.random()
		cdf = 0
		i = 0
		
		while cdf+probs[i] < rnum:
			cdf = cdf + probs[i]
			i = i + 1 
			
		ret.append(i)
	
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