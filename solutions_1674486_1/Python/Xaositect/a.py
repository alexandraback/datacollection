from sys import *

class Graph:
	def __init__(self, n):
		self.n = n
		self.edges = {}
		for i in xrange(1, n + 1):
			self.edges[i] = []
	def addEdge(self, fr, to):
		self.edges[fr].append(to)
	def __str__(self):
		return str(self.edges)

def readGraph(stream):
	N = int(stream.readline().strip())
	g = Graph(N)
	for i in xrange(1, N + 1):
		list = map(lambda x: int(x), stream.readline().split())[1:]
		for j in list:
			g.addEdge(i, j)
	return g

def paths(g, s):
	vert = [s]
	new_vert = []
	visited = set([s])
	while vert != []:
		for i in vert:
			for j in g.edges[i]:
				if j in visited:
					return True
				else:
					new_vert.append(j)
					visited.add(j)
		vert = new_vert
		new_vert = []

def solve(g):
	degs = {}
	for i in xrange(1, g.n + 1):
		degs[i] = 0
	for i in xrange(1, g.n + 1):
		for j in g.edges[i]:
			degs[j] += 1
	result = False
	for i in xrange(1, g.n + 1):
		if degs[i] == 0:
			result = result or paths(g, i)
	return result

def main(stream):
	T = int(stream.readline().strip())
	for i in xrange(1, T + 1):
		g = readGraph(stream)
		ans = solve(g)
		print "Case #%d: %s" % (i, "Yes" if ans else "No")

if __name__ == '__main__':
	main(stdin)
