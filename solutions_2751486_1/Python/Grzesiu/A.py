#!/usr/bin/python

from sys import stdin, stderr
from math import sqrt

def readiline():
	return map(int, stdin.readline().strip().split() )

tests = readiline()[0]

for test_no in xrange(1,tests+1):
	name, n = stdin.readline().strip().split()
	n = int(n)

	k = len(name)
	total = k*(k+1)/2
	start = 0
	cons = 0
	for end in xrange(len(name)):
		if name[end] in 'aeiou':
			cons = 0
		else:
			cons += 1
		
		if cons == n:
			start = end-n+2
			cons = n-1

		total -= end-start+1

	print "Case #%d: %d" % (test_no,total)
