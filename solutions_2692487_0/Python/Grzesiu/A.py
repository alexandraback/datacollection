#!/usr/bin/python

from sys import stdin, stderr
from math import sqrt

def readiline():
	return map(int, stdin.readline().strip().split() )

tests = readiline()[0]

for test_no in xrange(1,tests+1):
	size, n = readiline()
	arr = readiline()
	arr.sort()

	uses = 0
	best = n

	arr = zip( arr, range(n-1,-1,-1) )
	if size > 1:
		for a, n in arr:
			while size <= a:
				uses += 1
				size += size-1
			size += a
			best = min(best, n+uses)

		 
	print "Case #%d: %d" % (test_no,best)
