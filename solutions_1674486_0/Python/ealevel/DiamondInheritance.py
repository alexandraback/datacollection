def bfs(node, path=[]):
	queue = [node]
	while queue:
		v = queue.pop(0)
		if not v in path:
			path = path + [v]
			queue = queue + G[v]
	return path

T = int(raw_input())
for t in range(1, T+1):
	N = int(raw_input())
	G = []
	roots = [True] * N
	for i in range(N):
		line = map(int, raw_input().split())[1:]
		suc = []
		G.append(suc)
		for j in line:
			suc.append(j-1)
	
	parents = {}
	for i in range(N):
		parents[i] = set(bfs(i, []))
	
	diamond = False
	for node in range(N):
		if diamond:
			break
		visited = set()
		for v in G[node]:
			if diamond:
				break
			for p in parents[v]:
				if p in visited:
					diamond = True
					break
				else:
					visited.add(p)

	print "Case #{0}: {1}".format(t, "Yes" if diamond else "No")
