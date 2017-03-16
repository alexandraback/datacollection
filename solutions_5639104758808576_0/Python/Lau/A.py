#!/usr/bin/python
# -*- coding: utf-8 -*-

def solve(Smax, S):
	s = 0
	missing = 0
	for i in range(Smax+1):
		if s<i:
			missing += i-s
			s = i
		s += int(S[i])
	return missing

T=int(input())
for test in range(T):
	[Smax, S] = input().split()
	Smax = int(Smax)
	print ('Case #%d:' % (test+1), solve(Smax, S))
