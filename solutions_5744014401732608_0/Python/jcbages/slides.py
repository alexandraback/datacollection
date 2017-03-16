T = int(raw_input())
for t in range(T):
	vals = raw_input().split()
	N = int(vals[0])
	M = int(vals[1])
	G = [[] for x in range(N)]
	for i in range(N):
		for j in range(i+1, N):
			G[i].append(j)
	paths = [-1 for x in range(N)]
	paths[-1] = 0
	def count_paths(s, n):
		if paths[s] != -1: return paths[s]
		count = 0
		for v in G[s]:
			count_paths(v, n)
			count += paths[v]
		paths[s] = count
		if n-1 in G[s]: paths[s] += 1
	count_paths(0, N)
	def get_vertices(val):
		ans = []
		for i in range(len(paths)-1):
			if val >= paths[i]:
				ans.append(i)
				val -= paths[i]
		return ans
	if paths[0] < M:
		print 'Case #%d: IMPOSSIBLE' % (t+1)
		continue
	vertices = get_vertices(M)
	if vertices[0] != 0: G[0] = vertices
	paths = [-1 for x in range(N)]
	paths[-1] = 0
	count_paths(0, N)
	print 'Case #%d: POSSIBLE' % (t+1)
	for i in range(N):
		string = ['0' for x in range(N)]
		for v in G[i]: string[v] = '1'
		print ''.join(string)
