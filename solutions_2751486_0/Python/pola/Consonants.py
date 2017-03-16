#!/usr/bin/env python2
import sys

def cons_cons(w):
	tmp = w
	for v in "aeiou":
		tmp = tmp.replace(v, ' ')

	sz = [ len(x) for x in tmp.split(' ')]
	sz.sort(reverse=True)
	return sz[0]

def solve(w,n):
	res = 0
	for b in xrange(len(w)+1):
		for e in xrange(b,len(w)+1):
			if(cons_cons(w[b:e]) >= n):
				res+=1
	return res

cases = int(sys.stdin.readline())

for case in range(cases):
	line = sys.stdin.readline()[:-1].split(" ")
	w = line[0]
	n = int(line[1])
	print "Case #%d: %d" % (case+1,solve(w,n))

		