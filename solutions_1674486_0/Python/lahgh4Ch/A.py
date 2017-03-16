def BFS(adj, start):
	q = [start,]
	found = {start: True}
	while len(q) > 0:
		v = q.pop(0)
		for w in adj[v]:
			if w in found:
				return True
			found[w] = True
			q.append(w)
	else: return False

def judge(adj):
	for v in adj:
		if BFS(adj, v) == True: return 'Yes'
	else: return 'No'

T = int(raw_input())
for t in range(T):
	N = int(raw_input())
	adj = {}
	for n in range(N):
		M = raw_input()
		M = M.split()
		M.pop(0)
		for m in range(len(M)):
			M[m] = int(M[m])
		adj[n + 1] = M
	print 'Case #' + str(t + 1) + ':', judge(adj)
