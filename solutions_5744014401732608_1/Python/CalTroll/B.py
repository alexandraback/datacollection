def solve(B, M):
	if ((2 ** (B - 2)) < M):
		return False
	graph = []
	for i in range(B):
		graph.append([])
		for j in range(B):
			graph[i].append(0)
	for i in range(1, B):
		for j in range(i + 1, B):
			graph[i][j] = 1
	graph[0][B-1] = 1
	M -= 1
	c = 1
	while (M > 0):
		value = 2**(B - c - 2)
		if value <= M:
			M -= value
			graph[0][c] = 1
		c += 1
	return graph





T = input()
for i in range(T):
	B, M = tuple([int(el) for el in raw_input().split()])
	sol = solve(B, M)
	if not sol:
		print 'Case #' + str(i + 1) + ': ' + 'IMPOSSIBLE'
	else:
		print 'Case #' + str(i + 1) + ': ' + 'POSSIBLE'
		for row in sol:
			print ''.join([str(el) for el in row])


