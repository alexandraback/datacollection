import sys

T = int(sys.stdin.readline().strip())

def find(edges, degree):
	for i, d in degree.items():
		if d > 0:
			continue
		q = [i]
		visited = {}
		seen = {}
		while q:
			newq = []
			while q:
				n = q.pop()
				for j in edges[n]:
					if j in seen:
						return True
					newq.append(j)
					seen[j] = True
				visited[n] = True

			q = newq
	return False

for t in range(T):
	N = int(sys.stdin.readline().strip())
	edges = {}
	degree = {i: 0 for i in range(1, N + 1)}
	for n in range(1, N + 1):
		m = [int(m) for m in sys.stdin.readline().strip().split(' ')]
		M = m[0]
		m = m[1:]
		edges[n] = {}
		for i in m:
			edges[n][i] = True
			degree[i] += 1
	
	print('Case #{0}: {1}'.format(t + 1, 'Yes' if find(edges, degree) else 'No'))
