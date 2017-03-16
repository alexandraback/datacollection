#!/usr/bin/env python3

from itertools import *

def read_ints():
	return map(int, input().strip().split())

def bbin(a):
	return bin(a)[2:]

def test():
	a, b, c = read_ints()
	res = 0
	for x in range(a):
		for y in range(b):
			if x&y < c:
				res += 1

	return res

T, = read_ints()
for tnum in range(T):
	print("Case #{}: {}".format(tnum+1, test()))
