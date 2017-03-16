#!/usr/bin/python

fp = open('a.in')

tests = int(fp.readline()[:-1])
c = 1

def calc(k,r):
	return (2*r-3)*(k)+2*(k)*(k+1)

def recurs(low, high, r, t):
	if (high-low < 5):
		k = low
		while calc(k+1,r) <= t:
			k = k + 1
		return k
	elif (calc((low+high)/2, r) < t):
		return recurs((low+high)/2, high, r, t)
	elif (calc((low+high)/2, r) > t):
		return recurs(low, (low+high)/2, r, t)
	else:
		return (low+high)/2

while tests > 0:
	r, t = [int(x) for x in fp.readline()[:-1].split(' ')]
	
#	print r,t
	
	k = recurs(1, 1707106780, r, t)
		
	print "Case #%d: %d" % (c, k)
	
	c = c + 1
	tests = tests - 1