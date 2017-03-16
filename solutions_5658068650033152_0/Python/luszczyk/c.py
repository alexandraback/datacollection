#!/usr/bin/env python3

from itertools import *

def read_ints():
	return map(int, input().strip().split())

def test():
	n, m, k = read_ints()

	if min(n, m) == 1:
		return max(n, m)

	ms = float('+inf')

	for x in range(2, n+1):
		for y in range(2, m+1):
			stones = 2*(x-2) + 2*(y-2)
			enclosed = stones+ (x-2)*(y-2)
			ms = min(stones + max(0, k-enclosed), ms)

	return ms

T, = read_ints()
for x in range(T):
	print("Case #{}: {}".format(x+1, test()))
