#! /usr/bin/python

T = int(raw_input())

for t in range(1, T+1):

	K, C, S = [int(inp) for inp in raw_input().split()]

	if S*C < K:
		print 'Case #' + str(t) + ': ' + 'IMPOSSIBLE'
	else:
		tiles = []
		for grad in range(S):
			indices = [(grad*C + lvl) * (K**lvl) for lvl in range(C) if grad*C + lvl < K]
			if len(indices) > 0:
				tiles += [1 + sum(indices)]

		print 'Case #' + str(t) + ':',
		for tile in set(tiles):
			print tile,
		print