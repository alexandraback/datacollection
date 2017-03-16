
def bipartiteMatch(graph):
	'''Find maximum cardinality matching of a bipartite graph (U,V,E).
	The input format is a dictionary mapping members of U to a list
	of their neighbors in V.  The output is a triple (M,A,B) where M is a
	dictionary mapping members of V to their matches in U, A is the part
	of the maximum independent set in U, and B is the part of the MIS in V.
	The same object may occur in both U and V, and is treated as two
	distinct vertices if this happens.'''

	# initialize greedy matching (redundant, but faster than full search)
	matching = {}
	for u in graph:
		for v in graph[u]:
			if v not in matching:
				matching[v] = u
				break

	while 1:
		# structure residual graph into layers
		# pred[u] gives the neighbor in the previous layer for u in U
		# preds[v] gives a list of neighbors in the previous layer for v in V
		# unmatched gives a list of unmatched vertices in final layer of V,
		# and is also used as a flag value for pred[u] when u is in the first layer
		preds = {}
		unmatched = []
		pred = dict([(u,unmatched) for u in graph])
		for v in matching:
			del pred[matching[v]]
		layer = list(pred)

		# repeatedly extend layering structure by another pair of layers
		while layer and not unmatched:
			newLayer = {}
			for u in layer:
				for v in graph[u]:
					if v not in preds:
						newLayer.setdefault(v,[]).append(u)
			layer = []
			for v in newLayer:
				preds[v] = newLayer[v]
				if v in matching:
					layer.append(matching[v])
					pred[matching[v]] = v
				else:
					unmatched.append(v)

		# did we finish layering without finding any alternating paths?
		if not unmatched:
			unlayered = {}
			for u in graph:
				for v in graph[u]:
					if v not in preds:
						unlayered[v] = None
			return (matching,list(pred),list(unlayered))

		# recursively search backward through layers to find alternating paths
		# recursion returns true if found path, false otherwise
		def recurse(v):
			if v in preds:
				L = preds[v]
				del preds[v]
				for u in L:
					if u in pred:
						pu = pred[u]
						del pred[u]
						if pu is unmatched or recurse(pu):
							matching[v] = u
							return 1
			return 0

		for v in unmatched: recurse(v)

with open("data.txt", 'r') as f:
    with open("data1.txt", 'w') as g:
        T = int(f.readline())
        for j in range(T):
            N = int(f.readline())
            adjlist = dict()
            spares = 0
            numedges = 0
            firstwords, secondwords = set(), set()
            for i in range(N):
                numedges += 1
                first, second = f.readline().split()
                first += "uniquefirststring"
                second += "uniquesecondstring"
                firstwords.add(first)
                secondwords.add(second)
                if first not in adjlist:
                    adjlist[first] = set()
                if second not in adjlist[first]:
                    adjlist[first].add(second)
                else:
                    spares += 1
                if second not in adjlist:
                    adjlist[second] = set()
                adjlist[second].add(first)

            # print bipartiteMatch(adjlist)[0]
            n = len(bipartiteMatch(adjlist)[0])/2
            a = len(firstwords) - n
            b = len(secondwords) - n
            # print n, a, b, numedges
            result = numedges - (n + a + b)

            g.write("Case #%d: %d\n" % (j + 1, result))

