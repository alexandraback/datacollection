#!/usr/bin/env python
from sys import stdin

tn = int(stdin.readline())
for ti in xrange(tn):
	sm, ss = stdin.readline().split()
	sm = int(sm)
	r = 0
	db = 0
	for i in xrange(sm+1):
		x = int(ss[i])
		if i > db:
			r = r + i - db
			db = i
		db = db + x
	print 'Case #{0}:'.format(ti+1), r
