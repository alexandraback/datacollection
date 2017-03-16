import networkx, sys

for tc in xrange(1, int(sys.stdin.readline())+1):
	n = int(sys.stdin.readline())
	G = networkx.DiGraph()
	for i in xrange(1, n+1):
		pre = [int(w) for w in sys.stdin.readline().split()]
		if pre[0] == 0:
			continue
		pre = pre[1:]
		for j in pre:
			G.add_edge(j, i)
	for seq in G.nodes():
		G.node[seq]['val'] = 0
	order = networkx.topological_sort(G)
	found = False
	for src in order:
		valid = [ False ] * (n+1)
		#src
		valid[src] = True
		next = G.successors(src)
		while len(next) > 0:
			p = next[0]
			next.extend(G.successors(p))
			next.pop(0)
			if valid[p] == False:
				valid[p] = True
			else:
				found = True
				break
		if found: break
	if found:
		print "Case #%d: Yes" % tc
	else:
		print "Case #%d: No" % tc
		


