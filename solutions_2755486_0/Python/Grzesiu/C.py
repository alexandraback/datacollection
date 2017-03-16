#!/usr/bin/python

from sys import stdin, stderr
from math import sqrt

def readiline():
	return map(int, stdin.readline().strip().split() )

tests = readiline()[0]

for test_no in xrange(1,tests+1):
	n = readiline()[0]
	T = [ readiline() for i in xrange(n) ]
	attacks = []
	total = 0
	for di, ni, wi, ei, si, ddi, dpi, dsi in T:
		for i in xrange(ni):
			attack = (di+i*ddi, wi+i*dpi, ei+i*dpi, si+i*dsi)
			attacks.append(attack)

	attacks.sort()
	wall = {}
	fix = []
	now = 0
	for d, w, e, s in attacks:
		if now < d:
			for fw, fe, h in fix:
				for p in xrange(fw, fe):
					wall[p] = max( wall.get(p, 0), h )

			now = d
			fix = []


		ok = False
		for p in xrange(w, e):
			if wall.get(p, 0) < s:
				ok = True
				break

		#print >>stderr, d, (w, e), s, ok

		if ok:
			total += 1
			fix.append( (w, e, s) )
	print "Case #%d: %d" % (test_no,total)





