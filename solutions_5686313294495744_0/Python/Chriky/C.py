import codejam as gcj
import codejam.graphs as gph
gcj.load_input('C-small-attempt0.in')

T = gcj.read_input('i')
for t in range(T):
	N, pairs = gcj.read_input('i->', 's s')
	G = gph.Graph()
	G.add_edges_from(((0, a), (1, b)) for a, b in pairs)

	matching = gph.bipartite.maximum_matching(G)

	print 'Case #%i:' % (t + 1), N - (len(G) - (len(matching) / 2))

