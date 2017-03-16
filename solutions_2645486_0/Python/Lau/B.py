#!/usr/bin/python
# -*- coding: utf-8 -*-

def slice_gain(M,m,E,R,v):
	if len(v)==0:
		return 0
	i_max = []
	v_max = -1
	for i in range(len(v)):
		if v[i]==v_max:
			i_max.append(i)
		if v[i]>v_max:
			i_max = [i]
			v_max = v[i]
	max_gain = []
	for i in i_max:
		m2=min(M+i*R,E)
		M2=max(m-(len(v)-1-i)*R,0)
		a = slice_gain(M,max(m2-R,0),E,R,v[0:i])
		b = slice_gain(min(M2+R,E),m,E,R,v[i+1:len(v)])
		G = (m2-M2)*v[i]
		max_gain.append(a+G+b)
	return max(max_gain)

def solve():
	[E,R,N] = [int(i) for i in input().split()]
	v = [int(i) for i in input().split()]
	return slice_gain(E,0,E,R,v)

T = int(input())
for test in range(T):
	print ('Case #%d:' % (test+1), solve())
