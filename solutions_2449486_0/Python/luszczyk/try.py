#!/usr/bin/env python

def read_ints():
	return map(int, raw_input().strip().split())

T, = read_ints()

def comptab(s,t,n,m):
	for x in xrange(n):
		for y in xrange(m):
			if t[x][y] != s[x][y]:
				return False
	return True

for tc in xrange(1, T+1):
	n, m = read_ints()

	t = [ read_ints() for x in xrange(n) ]

	cutn = [0 for i in xrange(n)]
	cutm = [0 for i in xrange(m)]

	for x in xrange(n):
		for y in xrange(m):
			cutn[x] = max(cutn[x], t[x][y])
			cutm[y] = max(cutm[y], t[x][y])

	s = [ [ min(cutn[x], cutm[y]) for y in xrange(m) ] for x in xrange(n) ]

	print 'Case #{}: {}'.format(tc, comptab(s,t,n,m) and 'YES' or 'NO')		
