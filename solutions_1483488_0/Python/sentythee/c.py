#!/usr/bin/python

from sys import stdin
from math import *

lines = stdin.readlines()
n = int(lines[0].strip())

def d(x):
	if x > 0:
		return 1 + d(x / 10)
	
	return 0

def shift(x):
	cap = int(pow(10, digits-1))
	high = x / cap
	low = x % cap
	return low * 10 + high

for i in range(0, n):
	case = i+1
	line = lines[case]
	
	pairs = set()
	dups = 0
	
	start, end = [int(x) for x in line.split()]
	
	for i in range(start, end+1):
		digits = d(i)
		y = shift(i)
	
		while y != i:
			if y >= start and y <= end:
				new = [i,y]
				new.sort()
				pairs.add(new[0]*3000000+new[1])
				
			y = shift(y)
		
	
	out = len(pairs)	
	print 'Case #%d: %d' % (case, out)
	

