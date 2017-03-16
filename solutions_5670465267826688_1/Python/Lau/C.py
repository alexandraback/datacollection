#!/usr/bin/python
# -*- coding: utf-8 -*-

def transition(state, c):
	if c=='i':
		pol, val = [1,-1,-1,1], [1,0,3,2]
	elif c=='j':
		pol, val = [1,1,-1,-1], [2,3,0,1]
	elif c=='k':
		pol, val = [1,-1,1,-1], [3,2,1,0]
	return (state[0] * pol[state[1]], val[state[1]])

def loop(L, ijk, state, i, x):
	state = transition(state, ijk[i])
	i = (i+1)%L
	if i==0: x -= 1
	return (state, i, x)

def solve(L, X, ijk):
	i = 0
	x = X
	state = (1, 0)
	xmin = x-5
	while x > 0 and x > xmin and state != (1,1): state, i, x = loop(L, ijk, state, i, x)
	if x==0 or x==xmin: return "NO"
	state = (1, 0)
	xmin = x-5
	while x > 0 and x > xmin and state != (1,2): state, i, x = loop(L, ijk, state, i, x)
	if x==0 or x==xmin: return "NO"
	state = (1, 0)
	x %= 4
	while x > 0: state, i, x = loop(L, ijk, state, i, x)
	return "YES" if state == (1,3) else "NO"
			

T = int(input())
for test in range(T):
	[L,X] = [int(i) for i in input().split()]
	ijk = input()
	print ('Case #%d:' % (test+1), solve(L, X, ijk))
