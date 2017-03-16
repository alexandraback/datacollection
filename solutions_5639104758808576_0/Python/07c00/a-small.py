#!/usr/bin/env python
# -*- coding: utf-8 -*-

def solve(x):
	f = t = 0
	for i in range(len(x)):
		if t < i:
			 f += (i - t)
			 t += (i - t)
		t += x[i]
	return f

for i in range(int(raw_input())):
	(a, b) = raw_input().split()
	x = []
	for n in b:
		x.append(int(n))
	print 'Case #' + str(i+1) + ": " + str(solve(x))
