def solve(b, m):
	if m > 2**(b-2):
		return "IMPOSSIBLE", None
	graph = [[0 for j in xrange(b)] for i in xrange(b)]
	for i in xrange(1, b-1):
		graph[i][b-1] = 1
		for j in xrange(1, i):
			graph[i][j] = 1
	if m == 2**(b-2):
		graph[0] = [0] + (b-1) * [1]
	else:
		for j in xrange(b-2):
			if m & (1<<j):
				graph[0][j+1] = 1
	return "POSSIBLE", graph

T = int(raw_input())
for case in range(1, T+1):
	b, m = map(int, raw_input().split())
	s, sol = solve(b, m)
	print "Case #{}: {}".format(case, s)
	if sol is not None:
		for i in xrange(b):
			print ''.join(map(str, sol[i])) 