#!/usr/bin/pypy
import itertools
import sys

def test(n, m):
	n, m = str(n), str(m)
	for i in xrange(len(n)):
		if n == m[-i:] + m[:-i]:
			return True
	return False

def get(A, B):
	res = 0
	for n in xrange(A, B + 1):
		for m in xrange(n + 1, B + 1):
			if test(n, m):
				res += 1
	return res

def fast(A, B):
	res, l = 0, len(str(B))
	for i in xrange(A, B + 1):
		svd = set()
		d1, d2 = 1, 10**l
		for sh in xrange(l):
			re = i % d1
			p = i / d1 + (i % d1) * d2

			if  A <= p < i and not p in svd:
				res += 1
				svd.add(p)
			d1 *= 10
			d2 /= 10
				
	return res

if __name__ == '__main__':
	n = int(raw_input())
	for i in xrange(n):	
		a, b = map(int, raw_input().split())
		print "Case #{}: {}".format(i + 1, fast(a, b))

