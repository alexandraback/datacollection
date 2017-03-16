import sys
import itertools

def possible_x(m, n):
	if n == 0:
		return [[]]
	z = possible_x(m, n-1)
	y = [[i] + x for i in xrange(2,m+1) for x in z]
	return y
		
print possible_x(8,12)
