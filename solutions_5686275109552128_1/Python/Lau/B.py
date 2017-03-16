#!/usr/bin/python
# -*- coding: utf-8 -*-

import math

def solve(P):
	P.sort()
	P.reverse()
	opt = max(P)
	size = 1
	while size<opt:
		splits = 0
		for p in P:
			splits += math.ceil(p/size) - 1
			if splits + size > opt: break
		if splits + size < opt:
			opt = splits + size
		size += 1
	return opt

T = int(input())
for test in range(T):
	D = int(input())
	P = [int(i) for i in input().split()]
	print ('Case #%d:' % (test+1), solve(P))
