#!/usr/bin/python

T = int(raw_input())

def revInt(x):
	return int("".join(reversed(list(str(x)))))

def solve(n):
	seen = {}
	Q = [(1, 1)]
	i = 0
	while i < len(Q):
		x, moves = Q[i]
		i += 1
		if x == n:
			return moves
		if x + 1 < 20 * n and x + 1 not in seen:
			seen[x + 1] = 1
			Q.append((x + 1, moves + 1))
		y = revInt(x)
		if y < 20 * n and y not in seen:
			seen[y] = 1
			Q.append((y, moves + 1))

for tc in xrange(1, T + 1):
	n = int(raw_input())
	print "Case #%d: %d" % (tc, solve(n))
