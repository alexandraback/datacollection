T = input()
for t in range(1, T + 1):
	d = input()
	p = [int(x) for x in raw_input().split()]
	m = max(p)
	ans = m
	for i in range(1, m):
		ans = min(ans, i + sum([(x - 1) / i for x in p]))
	print "Case #%d: %d" % (t, ans)