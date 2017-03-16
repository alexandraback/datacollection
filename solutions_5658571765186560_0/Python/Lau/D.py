#!/usr/bin/python
# -*- coding: utf-8 -*-

def solve(X, R, C):
	if X >= 7: return "RICHARD"
	if (R*C) % X: return "RICHARD"

	if R < C: R, C = C, R
	if X > R: return "RICHARD"
	
	if C==1:
		if X >= 3: return "RICHARD"
	elif C==2:
		if X >= 4: return "RICHARD"
	elif C==3:
		if (X==5 and R==5) or X==6: return "RICHARD"
	
	return "GABRIEL"
			

T = int(input())
for test in range(T):
	[X,R,C] = [int(i) for i in input().split()]
	print ('Case #%d:' % (test+1), solve(X, R, C))
