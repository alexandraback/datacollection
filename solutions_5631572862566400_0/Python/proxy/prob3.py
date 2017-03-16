import networkx as nx

infile = open("input", "r")
outfile = open("output", "w")

cases = infile.readline()


for case in range(int(cases)):

	G = nx.DiGraph()
	N = infile.readline()
	G.add_nodes_from(range(1,int(N)))
	line = infile.readline()

	for i,x in enumerate(line.split(' ')):
		G.add_path([(i+1),int(x)])

	longest_len = 0
	for s in G.nodes():
		for t in G.nodes():
			path = list(nx.all_simple_paths(G,s,t))
			if len(path) > 0:
				if len(path[0]) > longest_len:
					longest = path[0]
					longest_len = len(path[0])
	if longest[0] == longest[-1]:
		del longest[-1]

	for s in G.nodes():
		if (s,longest[-1]) in G.edges() and s not in longest:
			longest.append(s)

	outfile.write("Case #" + str(int(case+1)) + ": " + str(len(longest)) + "\n")
