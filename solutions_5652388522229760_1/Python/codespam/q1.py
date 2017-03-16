#!/usr/bin/env pypy

import sys


d = map(int, sys.stdin.readlines()[1:])

for i, c in enumerate(d):
	print 'Case #%d:' % (i + 1),

	if c is 0:
		print 'INSOMNIA'
		continue

	seen = [False] * 10
	j = 0
	while not all(seen):
		j += 1
		for dig in str(c * j):
			seen[ord(dig) - ord('0')] = True
	print c * j

