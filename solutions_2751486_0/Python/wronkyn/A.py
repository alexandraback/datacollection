#!/usr/bin/python

import sys

T = int(sys.stdin.readline().split()[0])

def count(name, n):
	n_score = 0
	max_first_pos = -1
	total_consecutive = 0

	for i in xrange(len(name)):
		if name[i] not in 'aeiou':
			total_consecutive += 1
		else:
			total_consecutive = 0

		if total_consecutive >= n:
			max_first_pos = i - n + 1

		if max_first_pos >= 0:
			n_score += max_first_pos + 1

	return n_score

for i in xrange(T):
	name, n = sys.stdin.readline().split()

	print "Case #{0}: {3}".format(str(i+1), name, n, count(name, int(n)))
