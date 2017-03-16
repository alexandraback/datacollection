# Implementation for max-flow lifted from Wikipedia.

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
            residuals = [edge.capacity - self.flow[edge] for edge in path]
            flow = min(residuals)
            for edge in path:
                self.flow[edge] += flow
                self.flow[edge.redge] -= flow
            path = self.find_path(source, sink, [])
        return sum(self.flow[edge] for edge in self.get_edges(source))

# My code begins here.

import os, inspect

problemName  = 'C'
# Options are 'large', 'small', and 'example'.
testCase     = 'small'
# Only relevant for small test case.
attempt      = 0

def getMaximumMatching(firstWords, secondWords, uncoveredFirstWords, uncoveredSecondWords, lines):
  validEdges          = [((line[0], 0), (line[1], 1)) for line in lines if line[0] in uncoveredFirstWords and line[1] in uncoveredSecondWords]
  verticesToNeighbors = {}
  verticesToNeighbors['source'] = [(firstWord, 0) for firstWord in uncoveredFirstWords]
  verticesToNeighbors['sink']   = []
  for firstWord in uncoveredFirstWords:
    verticesToNeighbors[(firstWord, 0)] = [edge[1] for edge in validEdges if edge[0] == (firstWord, 0)]
  for secondWord in uncoveredSecondWords:
    verticesToNeighbors[(secondWord, 1)] = ['sink']

  network = FlowNetwork()
  [network.add_vertex(v) for v in verticesToNeighbors]
  for vertex in verticesToNeighbors:
    for vertex2 in verticesToNeighbors[vertex]:
      network.add_edge(vertex, vertex2, 1)
  return network.max_flow('source', 'sink')

def minimumCovering(firstWords, secondWords, uncoveredFirstWords, uncoveredSecondWords, lines):
  requiredIndices = set()

  for firstWord in firstWords:
    if len(firstWords[firstWord]) == 1:
      requiredIndices.add(firstWords[firstWord][0])

  for secondWord in secondWords:
    if len(secondWords[secondWord]) == 1:
      requiredIndices.add(secondWords[secondWord][0])

  for index in requiredIndices:
    [firstWord, secondWord] = lines[index]
    if firstWord in uncoveredFirstWords:
      uncoveredFirstWords.remove(firstWord)
    if secondWord in uncoveredSecondWords:
      uncoveredSecondWords.remove(secondWord)

  maximumMatching = getMaximumMatching(firstWords, secondWords, uncoveredFirstWords, uncoveredSecondWords, lines)

  return len(requiredIndices) + len(uncoveredFirstWords) + len(uncoveredSecondWords) - maximumMatching

def solution(lines):
  firstWords  = {}
  secondWords = {}

  for index in xrange(len(lines)):
    [firstWord, secondWord] = lines[index]
    if firstWord not in firstWords:
      firstWords[firstWord] = []
    firstWords[firstWord].append(index)
    if secondWord not in secondWords:
      secondWords[secondWord] = []
    secondWords[secondWord].append(index)

  uncoveredFirstWords  = set(firstWords.keys())
  uncoveredSecondWords = set(secondWords.keys())

  return len(lines) - minimumCovering(firstWords, secondWords, uncoveredFirstWords, uncoveredSecondWords, lines)

currentDir   = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
if testCase in ['large', 'example']:
  inputString  = problemName + ('-%s' % testCase)
  outputString = problemName + ('-%s' % testCase)
else:
  inputString  = problemName + ('-%s-attempt%d' % (testCase, attempt))
  outputString = problemName + ('-%s' % testCase)

inFile       = os.path.join(currentDir, 'inputfiles', '%s.in' % inputString)
outFile      = os.path.join(currentDir, 'outputfiles', '%s.out' % outputString)

if os.path.exists(outFile):
  os.remove(outFile)

with open(inFile, 'r') as inputfile:
  numberOfCases = int(inputfile.readline())
  for case in xrange(1, numberOfCases + 1):
    n = int(inputfile.readline())
    lines = []
    for _ in xrange(n):
      [x, y] = inputfile.readline().strip().split(' ')
      lines.append([x, y])

    # Get the result here
    result = solution(lines)

    with open(outFile, 'a') as f:
      f.write('Case #%d: %d\n' % (case, result))
