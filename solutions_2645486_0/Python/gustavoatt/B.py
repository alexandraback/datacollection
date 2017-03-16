#!/usr/bin/env python
import sys

def dp(i, curr_ener, table):
	if i >= N:
		return 0

	if (i, curr_ener) in table:
		return table[i, curr_ener]

	val = float("-inf")
	for x in xrange(curr_ener + 1):
		next_ener = min(E, curr_ener - x + R)
		val = max(val, x * values[i] + dp(i + 1, next_ener, table))

	table[i, curr_ener] = val
	return val

if __name__ == '__main__':
	T = int(sys.stdin.readline().strip())
	for CASE in xrange(1, T + 1):
		E, R, N = map(int, sys.stdin.readline().strip().split())
		values  = map(int, sys.stdin.readline().strip().split())

		print "Case #{}: {}".format(CASE, dp(0, E, dict()))

