def solve():
	n, m = map(int, raw_input().split())
	need = [map(int, raw_input().split()) for _ in xrange(n)]
	have = [[100] * m for _ in xrange(n)]
	for i in xrange(n):
		h = max(need[i])
		for j in xrange(m):
			have[i][j] = min(have[i][j], h)
	for i in xrange(m):
		h = max([need[j][i] for j in xrange(n)])
		for j in xrange(n):
			have[j][i] = min(have[j][i], h)
			if have[j][i] != need[j][i]: return "NO"
	return "YES"

for i in xrange(input()):
	print "Case #%d: %s" % (i + 1, solve())
