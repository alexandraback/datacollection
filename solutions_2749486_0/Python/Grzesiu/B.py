#!/usr/bin/python

from sys import stdin, stderr
from math import sqrt
from pprint import pprint

def readiline():
	return map(int, stdin.readline().strip().split() )


def small(x,y):
	ans = ''
	if x > 0:
		ans += 'WE' * abs(x)
	if x < 0:
		ans += 'EW' * abs(x)
	if y > 0:
		ans += 'SN' * abs(y)
	if y < 0:
		ans += 'NS' * abs(y)
	return ans

tests = readiline()[0]
for test_no in xrange(1,tests+1):
	x, y = readiline()
	
	ans = small(x,y)

	print "Case #%d: %s" % (test_no, ans)
