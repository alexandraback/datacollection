#!/usr/bin/python
import sys
from math import log

a, b, c = 0, 0, 0
search_until = 10000000000

def bin_search(x, y):
	while (True):
		mid = x+(y-x)/2
		if c > a*mid*mid + b*mid and c < a*(mid+1)*(mid+1) + b*(mid+1): 
			return mid
		elif c == a*mid*mid + b*mid:
			return mid
		elif c > a*mid*mid + b*mid:
			x = mid+1
		else:
			y = mid	

t = int(sys.stdin.readline())
for ctr in range(1, t+1):
	r, t = [int(x) for x in sys.stdin.readline().split()]	
	a0 = (r+1)*(r+1)-r*r
	c = 2*t
	b = 2*a0-4
	a = 4
	print "Case #{0}: {1}".format(ctr, int(bin_search(1, search_until)))