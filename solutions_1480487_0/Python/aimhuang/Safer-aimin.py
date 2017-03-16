#!/usr/bin/env python
from sys import stdin


def fun1(s):
	global PP
	return s<PP
def fun2(s):
	global PP
	global MM
	if(s<PP):
		return 100.0*(PP-s)/MM
	else:
		return 0

T=int(stdin.readline())
for C in range(1, T+1):
	S=map(int, stdin.readline().split())
	n=S.pop(0)
	MM=sum(S)
	PP=2.0*MM/n
	while True:
		L=filter(fun1, S)
		l=len(L)
		N=sum(L)
		if l==n: break
		n=l
		PP=1.0*(MM+N)/n
	S=map(fun2, S)
	print 'Case #%d:'%C, ' '.join(map(str, S))
