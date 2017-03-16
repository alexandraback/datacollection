#!/usr/bin/python

import math

T = input()
for t in range(1, T + 1):
	K, C, S = [int(x) for x in raw_input().split()]

	result = 'IMPOSSIBLE'
	indices = []
	if S >= math.ceil(K / float(C)):
		for base in range(0, K - C + 1, C):
			index = base
			for n in range(base + 1, base + C):
				index *= K
				index += n
			indices.append(index + 1)
		if K % C != 0:
	   		index = C * (K / C)
			for n in range(index + 1, K):
				index *= K
				index += n
			indices.append(index + 1)

	if len(indices) > 0:
		result = ' '.join(str(x) for x in indices)

	print "Case #%d: %s" % (t, result)
