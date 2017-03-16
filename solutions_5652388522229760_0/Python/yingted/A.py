#!/usr/bin/env python

T = int(raw_input())
for t in xrange(1, 1 + T):
	print 'Case #%d:' % t,
	N = int(raw_input())
	if N == 0:
		print 'INSOMNIA'
	else:
		s = set(xrange(10))
		for i in xrange(1, 999):
			s -= set(map(int, str(i * N)))
			if len(s) == 0:
				print i * N
				break
