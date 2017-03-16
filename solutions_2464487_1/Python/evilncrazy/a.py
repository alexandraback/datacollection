import math
import sys

def solve(r, t):
	r, t = int(r), int(t)

	best = 0
	lo, hi = 0, t
	while lo <= hi:
		n = (lo + hi) / 2
		if (n * r * 4 + n * (4 * n - 2) <= 2 * t):
			best = max(best, n)
			lo = n + 1
		else:
			hi = n - 1

	return best

for t, line in enumerate(sys.stdin.readlines()[1:]):
	count = solve(*line.rstrip().split(' '))
	print 'Case #%d:' % (t+1), int(count)
