#!/usr/bin/env python
from sys import stdin

tn = int(stdin.readline())
for ti in xrange(tn):
	stdin.readline()
	s = map(int, stdin.readline().split())
	print 'Case #{0}:'.format(ti+1), min(t + sum((x-1)//t for x in s) for t in xrange(1, 2000))
