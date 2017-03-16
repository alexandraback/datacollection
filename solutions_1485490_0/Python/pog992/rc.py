#!/usr/bin/env python
# -*- coding: utf-8 -*-

def rt(f):
	ws = ' \t\n'
	while True:
		c = f.read(1)
		if c not in ws: break
	l = [c]
	while True:
		c = f.read(1)
		if c in ws: break
		l.append(c)
	return ''.join(l)

def ri(f): return int(rt(f))
def rf(f): return float(rt(f))

mem = {}

def compute(a,b):
	if not a or not b: return 0
	
	ilea, czegoa = a[-1]
	ileb, czegob = b[-1]
	if not ilea: return result(a[:-1], b)
	if not ileb: return result(a, b[:-1])
	
	if czegoa != czegob:
		return max(result(a[:-1], b), result(a, b[:-1]))
	else:
		dod = min(ilea, ileb)
		ilea -= dod
		ileb -= dod
		return result(a[:-1]+[(ilea,czegoa)], b[:-1]+[(ileb,czegob)])+dod
		

def result(a,b):
	ta, tb = tuple(a), tuple(b)
	try:
		return mem[(ta,tb)]
	except KeyError:
		res = compute(a,b)
		mem[(ta,tb)] = res
		return res
			
		
		

from sys import stdin
t = ri(stdin)
for testcase in xrange(1, t+1):
	n, m = ri(stdin), ri(stdin)
	a, b = [],[]
	for _ in xrange(n):
		a.append((ri(stdin), ri(stdin)))
	for _ in xrange(m):
		b.append((ri(stdin), ri(stdin)))
	print "Case #%d: %d"%(testcase, result(a,b))
	
