# wiki
class Edge(object):
	def __init__(self, u, v, w=1):
		self.source = u
		self.sink = v  
		self.capacity = w
	def __repr__(self):
		return "%s->%s:%s" % (self.source, self.sink, self.capacity)

class FlowNetwork(object):
	def __init__(self):
		self.adj = {}
		self.flow = {}
 
	def add_vertex(self, vertex):
		if vertex not in self.adj:
			self.adj[vertex] = []
 
	def get_edges(self, v):
		return self.adj[v]
 
	def add_edge(self, u, v, w=1):
		if u == v:
			raise ValueError("u == v")
		edge = Edge(u,v,w)
		redge = Edge(v,u,0)
		edge.redge = redge
		redge.redge = edge
		self.adj[u].append(edge)
		self.adj[v].append(redge)
		self.flow[edge] = 0
		self.flow[redge] = 0
 
	def find_path(self, source, sink, path):
		if source == sink:
			return path
		for edge in self.get_edges(source):
			residual = edge.capacity - self.flow[edge]
			if residual > 0 and edge not in path:
				result = self.find_path( edge.sink, sink, path + [edge]) 
				if result != None:
					return result
 
	def max_flow(self, source, sink):
		path = self.find_path(source, sink, [])
		while path != None:
			residuals = [edge.capacity - self.flow[edge] for edge in path]
			flow = min(residuals)
			for edge in path:
				self.flow[edge] += flow
				self.flow[edge.redge] -= flow
			path = self.find_path(source, sink, [])
		return sum(self.flow[edge] for edge in self.get_edges(source))

def main():
	T = int(input())
	for k in range(1,T+1):
		N = int(input())
		g = FlowNetwork()
		l = [ (lambda k: ('1_' + k[0], '2_' + k[1]))(input().split()) for _ in range(N)]
		d1 = set()
		d2 = set()
		for i,j in l:
			d1.add(i)
			d2.add(j)
			g.add_vertex(i)
			g.add_vertex(j)
			g.add_edge(i,j)
		g.add_vertex('s')
		g.add_vertex('t')
		for i in d1:
			g.add_edge('s',i)
		for j in d2:
			g.add_edge(j,'t')
		r = g.max_flow('s','t')
		print('Case #%d: %d' % (k,N-len(g.adj)+2+r))



if __name__ == '__main__':
	main()