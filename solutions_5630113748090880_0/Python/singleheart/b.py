#!/usr/bin/python

import math

T = input()
for t in range(1, T + 1):
	N = input()
	H = []
	for n in range(1, 2 * N):
		h = [int(x) for x in raw_input().split()]
		H.append(h)
	frequency = [0] * 2501
	for hs in H:
	 	for h in hs:
	 		frequency[h] += 1

	result = []
	for i, f in enumerate(frequency):
		if f % 2 != 0:
			result.append(i)

	result.sort()

	print "Case #%d: %s" % (t, ' '.join(str(x) for x in result))
