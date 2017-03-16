#!/usr/bin/env python
from __future__ import division
from sys import stdin
T=int(stdin.readline())
for C in range(1, T+1):
	S=map(int, stdin.readline().split())
	n=S.pop(0)
	M=sum(S)
	m=2*M/n
	L=filter(lambda s: s<m, S)
	l=len(L)
	N=sum(L)
	S=map(lambda s: 100*((M+N)/l-s)/M if s<m else 0, S)
	print 'Case #%d:'%C, ' '.join(map(str, S))
