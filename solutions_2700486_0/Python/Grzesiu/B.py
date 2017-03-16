#!/usr/bin/python

from sys import stdin, stderr
from math import sqrt
from pprint import pprint

def readiline():
	return map(int, stdin.readline().strip().split() )

PASCAL_N = 1024
PASCAL = [ [0] * PASCAL_N for i in xrange(PASCAL_N) ]
for n in xrange(PASCAL_N):
	PASCAL[n][0] = 1
	for k in xrange(1,n+1):
		PASCAL[n][k] = PASCAL[n-1][k-1] + PASCAL[n-1][k]

def binom(n,k):
	return PASCAL[n][k]

def binom_sum(n,k):
	s = 0
	for i in xrange(k,n+1):
		s += PASCAL[n][i]
	return s

tests = readiline()[0]

for test_no in xrange(1,tests+1):
	n, x, y = readiline()
	x = abs(x)
	l = x+y
	q = l-1
	n -= q*(q+1)/2

	k = y+1
	if n < k:
		p = 0.0
	elif n >= l+k:
		p = 1.0
	elif x == 0:
		p = 0.0
	else:	
		if n > l:
			s = n-l
			n -= 2*s
			k -= s

		p = 1.0*binom_sum(n,k) / (2**n)
		 
	p = ('%.15f' % p).rstrip('0')
	if p[-1] == '.': p += '0'
	print "Case #%d: %s" % (test_no, p)
