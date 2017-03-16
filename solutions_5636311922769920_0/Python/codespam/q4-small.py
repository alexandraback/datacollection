#!/usr/bin/env pypy

import sys


d = [map(int, l.split()) for l in sys.stdin.readlines()[1:]]

#xxx    012
#x...x...x   0 4 8
#x............x............x  0 13 26
#0123456789a123456789b123456

def expand(K, C):
	if K == 1:
		return [0]
	return [((K ** C) - 1) / (K - 1) * i for i in range(K)]

#print expand(3, 2)

for i, (K, C, S) in enumerate(d):
	print 'Case #%d:' % (i + 1),

	assert K == S

	r = expand(K, C)

	print ' '.join(str(x + 1) for x in r)
