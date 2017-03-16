import sys
sys.setrecursionlimit(10001)

def dp(e, n):
	if n == N:
		return 0
	if (e, n) in table:
		return table[e, n]
	gain = 0
	for i in xrange(0, e + 1):
		gain = max(gain, i * V[n] + dp(min(E, e - i + R), n + 1))
	table[e, n] = gain
	return gain

T = int(sys.stdin.readline().strip())
for t in xrange(1, T+1):
	E, R, N = map(int, sys.stdin.readline().strip().split())
	V = map(int, sys.stdin.readline().strip().split())
	table = {}

	print "Case #{}: {}".format(t, dp(E, 0))
