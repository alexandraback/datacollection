#/usr/bin/python

import sys
from fractions import gcd

t = int(sys.stdin.readline())

for ii in range(t):
	m = map(int, sys.stdin.readline().split('/'))

	p,q = m[0], m[1]

	x = gcd(p,q)
	p = p / x
	q = q / x

	if (q != 0 and (q & (q-1)) == 0):
		result = 0
		while (p < q):
			q = q >> 1
			result += 1
	else:
		result = "impossible"

	print "Case #{0:0d}:".format(ii+1), result