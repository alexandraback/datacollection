#!/usr/bin/env python3

from itertools import *

def read_ints():
	return map(int, input().strip().split('/'))

def gcd(a, b):
	return a if b==0 else gcd(b, a%b)

def test():
	p, q = read_ints()
	d = gcd(p, q)
	p, q = p//d, q//d

	v2d = 0
	while not q%2:
		v2d += 1
		q //= 2
	
	if q != 1:
		return "impossible"
	
	bit = 0
	while p//2:
		p//=2
		bit += 1

	return v2d-bit
			


T, = read_ints()
for x in range(T):
	print("Case #{}: {}".format(x+1, test()))
