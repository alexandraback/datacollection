def solve(graph):
	recip = {}
	for i in range(len(graph)):
		if graph[graph[i]] == i:
			recip[i] = 1
	visited = set()
	max_cycle = 0
	for i in range(len(graph)):
		if i in recip:
			continue
		visited = set()
		next = i
		length = 0
		while next not in visited:
			visited.add(next)
			next = graph[next]
			length += 1
			if next in recip:
				recip[next] = max(length + 1, recip[next])
				break
		if next == i:
			max_cycle = max(length, max_cycle)
	return max(max_cycle, sum(recip.values()))



T = input()
for i in range(T):
	N = input()
	graph = [int(n) - 1 for n in raw_input().split()]
	print 'Case #' + str(i + 1) + ': ' + str(solve(graph))