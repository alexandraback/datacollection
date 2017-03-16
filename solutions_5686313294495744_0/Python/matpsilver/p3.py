class Edge(object):
    def __init__(self, u, v, w):
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
        self.adj[vertex] = []
 
    def get_edges(self, v):
        return self.adj[v]
 
    def add_edge(self, u, v, w=0):
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
            print path
            residuals = [edge.capacity - self.flow[edge] for edge in path]
            flow = min(residuals)
            for edge in path:
                self.flow[edge] += flow
                self.flow[edge.redge] -= flow
            path = self.find_path(source, sink, [])
        return sum(self.flow[edge] for edge in self.get_edges(source))

def getInputCases():
	inputFile = open('input.txt', 'r')
	lines = [line.strip('\n') for line in inputFile]
	lines.pop(0)
	cases = []
	while(len(lines)!=0):
		number = int(lines[0])
		lines.pop(0)
		cases.append(lines[0:number])
		lines = lines[number:]

	return cases

def solveCases(cases):
	results = []
	for case in cases:
		g = FlowNetwork()
		vAs = set()
		vBs = set()
		for topic in case:
			words = topic.split(' ')
			vA = "A" + words[0]
			vB = "B" + words[1]
			vAs.add(vA)
			vBs.add(vB)
			g.add_vertex(vA)
			g.add_vertex(vB)
		for topic in case:
			words = topic.split(' ')
			vA = "A" + words[0]
			vB = "B" + words[1]
			g.add_edge(vA, vB, 1)
		sink = "sink"
		source = "source"
		g.add_vertex(sink)
		g.add_vertex(source)
		print (list(vAs))
		print (list(vBs))
		for vA in vAs:
			g.add_edge(source, vA, 1)
		for vB in vBs:
			g.add_edge(vB, sink, 1)
		maxFlow = g.max_flow(source, sink)
		words = len(vAs) + len(vBs)
		result = maxFlow + (words - (2 * maxFlow))
		result = len(case) - result
		results.append(result)
	return results

def outputResults(results):
	outputFile = (open('output.txt', 'w'))
	for i, result in enumerate(results):
		outputFile.write('Case #' + str(i+1) + ': ' + str(result))
		outputFile.write('\n')
	outputFile.close()

inputCases = getInputCases()
print inputCases
results = solveCases(inputCases)
outputResults(results)

