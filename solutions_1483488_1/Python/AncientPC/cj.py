#!/usr/bin/env python2

def permutations(a,b,x):
	#print "[%d] =" % x,

	y = str(x)
	cnt = 0
	for i in range(1,len(y)):
		j = int(y[i:]+y[:i])
		if j == x:
			break
		elif j > x and j >= a and j <= b:
			cnt += 1
			#print j,

	#print
	return cnt

nc = int(raw_input())
for c in xrange(nc):
	global p
	a, b = map(int,raw_input().split())

	cnt = 0
	for i in range(a,b+1):
		cnt += permutations(a,b,i)

	print "Case #%i: %i" % (c+1, cnt)
