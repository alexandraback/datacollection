import sys

lines = sys.stdin.readlines()

T = int(lines[0])

memo = {}

def prel(cur, target):
	global memo

	if cur <= target:
		return 0
	
	if (cur, target) in memo:
		return memo[(cur, target)]
	else:
		ans = 1 + prel(cur - target, target)
		memo[(cur, target)] = ans
		return ans

def solve(P):
	M = max(P)
	best = M
	for minlev in xrange(1, M):
		prel_time = sum(map(lambda x: prel(x, minlev), P))
		# print "minlev: %d prel_time: %d" % (minlev, prel_time)
		best = min(best, prel_time + minlev)

	return best

for t in xrange(1, T + 1):
	P = map(int, lines[2 * t].split())

	print "Case #%d: %d" % (t, solve(P))