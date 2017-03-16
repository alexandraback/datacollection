#!/usr/bin/env pypy

import sys


d = sys.stdin.readlines()

for i, c in enumerate(d[1:]):
	print 'Case #%d:' % (i + 1),

	B, M = map(int, c.split())

	if M > 2 ** (B - 2):
		print 'IMPOSSIBLE'
		continue

	print 'POSSIBLE'

	for fr in range(B):
		for to in range(B):
			if not fr:
				if to != B - 1:
					sys.stdout.write('1' if (M - 1) & (1 << (B - to - 2)) else '0')
				else:
					sys.stdout.write('1' if M >= 1 else '0')
			elif fr < B - 1:
				sys.stdout.write('1' if to > fr else '0')
			else:
				sys.stdout.write('0')
		print
