#!/usr/bin/env python2

def read_ints():
	return map(int, raw_input().strip().split())

T,  = read_ints()

for ct in range(T):
	e, r, n = read_ints()
	v = read_ints()

	x = [ 0 for t in range(e+1) ]

	for w in reversed(v):
		y = [ reduce(max, [ w*u + x[min(k-u+r, e)] for u in range(0, k+1) ], 0) \
				for k in range(e+1) ]
		x = y

	print 'Case #{}: {}'.format(ct+1, x[-1])

