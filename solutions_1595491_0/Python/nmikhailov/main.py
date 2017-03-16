#!/usr/bin/pypy
import itertools
import sys

d = [1, 0, 1]

if __name__ == '__main__':
	n = int(raw_input())
	for i in xrange(n):
		arr = map(int, raw_input().split())
		s, p = arr[1:3]
		
		res = 0
		for x in  arr[3:]:
			if x == 0 and p > 0:
				continue
			c = (x + 2) / 3
			if c >= p:
				res += 1
			elif c + d[x % 3] >= p and s > 0:
				res += 1
				s -= 1

		print "Case #{}: {}".format(i + 1, res)

