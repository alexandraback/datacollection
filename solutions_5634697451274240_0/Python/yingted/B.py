#!/usr/bin/env python
import itertools

def flip(a, _flipped={'-': '+', '+': '-'}):
	return list(map(_flipped.__getitem__, reversed(a)))

T = int(raw_input())
for t in xrange(1, 1 + T):
	print 'Case #%d:' % t,
	S = list(raw_input().strip())
	S = [key for key, count in itertools.groupby(S)]
	print S[:1].count('-') + S[1:].count('-') * 2
