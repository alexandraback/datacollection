def solve(b, m):
	ans = [[0 for i in range(b)] for j in range(b)]
	ans[0][b-1] = 1
	m = m -1
	for i in range(1, b-1):
		ans[0][i] = 1
		for j in range(i+1, b-1):
			ans[i][j] = 1

	index = 1
	while m > 0 and index < b-1:
		r = m % 2
		# print (m, r)
		if r == 1:
			ans[index][b-1] = 1
		m = int(m / 2)
		index = index + 1
	if m > 0:
		return (False, ans)
	else:
		return (True, ans)

T = input()
for i in range(T):
	p = map(int, raw_input().split())
	ans = solve(p[0], p[1])
	if ans[0]:
		print "Case #%d: %s" % ((i+1), "POSSIBLE")
		for row in ans[1]:
			print "".join([str(x) for x in row])
	else:
		print "Case #%d: %s" % ((i+1), "IMPOSSIBLE")
