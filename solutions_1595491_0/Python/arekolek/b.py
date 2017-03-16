#!/usr/bin/python

from sys import stdin
import re

# compute possible triplets for each total
triplets = {t:[(i,j,k) for i in xrange(11) for j in xrange(i,i+3) for k in xrange(j,i+3) if i+j+k==t and j<11 and k<11] for t in xrange(31)}

maxes = {t:[max(triplet) for triplet in triplets[t]] for t in triplets}

T = int(stdin.readline())

for i in xrange(1,T+1):
	result = 0
	line = map(lambda x:int(x), stdin.readline().split(' '))
	n = line[0]
	s = line[1]
	p = line[2]
	t = line[3:]
	for ti in t:
		if min(maxes[ti])==p-1 and max(maxes[ti])==p and s>0:
			s -= 1
			result += 1
		elif min(maxes[ti]) >= p:
			result += 1
	print 'Case #{0}: {1}'.format(i, result)
