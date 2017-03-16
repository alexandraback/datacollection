#!/usr/bin/env python
import sys

def num_circles(r, t):
	count = 0
	while t > 0:
		if (r + 1) * (r + 1) - r * r <= t:
			count += 1
			t -= (r + 1) * (r + 1) - r * r
			r += 2
		else:
			break

	return count

if __name__ == '__main__':
	T = int(sys.stdin.readline().strip())
	for CASE in xrange(1, T + 1):
		r, t = map(int, sys.stdin.readline().strip().split())
		print "Case #{}: {}".format(CASE, num_circles(r, t))

