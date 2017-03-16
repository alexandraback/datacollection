#!/usr/bin/python

fp = open('a.in')

tests = int(fp.readline()[:-1])
c = 1

while tests > 0:
	r, t = [int(x) for x in fp.readline()[:-1].split(' ')]
	
#	print r,t
	k = 0
	while t >= (2*r+4*(k+1)-3):		
		k = k + 1
		t = t - (2*r+4*k-3)
	
	print "Case #%d: %d" % (c, k)
	
	c = c + 1
	tests = tests - 1