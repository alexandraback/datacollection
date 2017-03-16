#!/usr/bin/python

import math

def find(J, P, S, K):
	cjp = [[0] * (P + 1) for x in range(J + 1)]
	cjs = [[0] * (S + 1) for x in range(J + 1)]
	cps = [[0] * (S + 1) for x in range(P + 1)]

	result = []
	for s in range(1, S + 1):
		for p in range(1, P + 1):
			for j in range(1, J + 1):
				if cjp[j][p] + 1 <= K and cjs[j][s] + 1 <= K and cps[p][s] + 1 <= K:
					result.append(' '.join([str(j), str(p), str(s)]))
					cjp[j][p] += 1
					cjs[j][s] += 1
					cps[p][s] += 1
	return result

T = input()
for t in range(1, T + 1):
	J, P, S, K = [int(x) for x in raw_input().split()]

	result = find(J, P, S, K)

	print "Case #%d: %s" % (t, len(result))
	for s in result:
		print s
