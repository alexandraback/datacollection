#!/usr/bin/env pypy

import sys



d = [map(int, l.split()) for l in sys.stdin.readlines()[1:]]

def print_(x):
	#print x
	return x

for i, (K, C, S) in enumerate(d):
	print 'Case #%d:' % (i + 1),

	r = set()
	#print
	for j in range(K / C + (1 if K % C else 0)):
		r.add(sum(K ** (C - 1 - x) * print_(j * C + x if j * C + x < K else 0) for x in range(C)))
		#print '-'
	
	if len(r) <= S:
		print ' '.join(str(n + 1) for n in r)
	else:
		print 'IMPOSSIBLE'
