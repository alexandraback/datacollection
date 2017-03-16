#!/usr/bin/env python
import sys

def up_to_n(r, n):
	return (n + 1) * (2 * n + 2 * r + 1)

def binary_search_last(r, t):
	x = 0
	y = t
	while x < y:
		mid = x + (y - x + 1) / 2;
		if up_to_n(r, mid) <= t:
			x = mid
		else:
			y = mid - 1
	return x + 1

def num_circles(r, t):
	count = 0
	while t > 0:
		if 2*r + 1 <= t:
			count += 1
			t -= 2 * r + 1
			r += 2
		else:
			break

	return count

if __name__ == '__main__':
	T = int(sys.stdin.readline().strip())
	for CASE in xrange(1, T + 1):
		r, t = map(int, sys.stdin.readline().strip().split())
		print "Case #{}: {}".format(CASE, binary_search_last(r, t))

