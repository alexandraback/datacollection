#!/usr/bin/env python
import sys
import collections

def dp(mask, table):
	if mask == 0:
		return []
	if mask in table:
		return table[mask]

	for chest in xrange(n):
		# Lets try to open the chest if possible
		if (mask & (1 << chest)) and keys[required[chest]] > 0:
			# Use the key and collect the booty
			keys[required[chest]] -= 1
			for booty in treasure[chest]:
				keys[booty] += 1

			# Solve without this chest
			res = dp(mask ^ (1 << chest), table)
			if res is not None:
				table[mask] = [chest] + res
				return table[mask]

			# Un-use the key and re-store the booty
			keys[required[chest]] += 1
			for booty in treasure[chest]:
				keys[booty] -= 1

	table[mask] = None
	return table[mask]

if __name__ == '__main__':
	T = int(sys.stdin.readline().strip())

	for CASE in xrange(1, T+1):
		k, n = map(int, sys.stdin.readline().strip().split())
		keys = collections.Counter()
		
		for x in map(int, sys.stdin.readline().strip().split()):
			keys[x] += 1

		treasure = []
		required = []
		for i in xrange(n):
			line = map(int, sys.stdin.readline().strip().split())
			t, booty = line[0], line[2:]

			required.append(t)
			treasure.append(booty)
		
		init_mask = (1 << n) - 1
		answer = dp(init_mask, dict())
		if answer is None:
			print "Case #{}: IMPOSSIBLE".format(CASE)
		else:
			print "Case #{}:".format(CASE),
			for i, x in enumerate(answer):
				if i + 1 == len(answer):
					print x + 1
				else:
					print x + 1, 