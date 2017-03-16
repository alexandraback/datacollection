"""Usage:
    pypy X.py < X-size.in > X-size.out
or sometimes
    python X.py < X-size.in > X-size.out
"""

# modified from http://code.activestate.com/recipes/117228/
# Priority dictionary using binary heaps
# David Eppstein, UC Irvine, 8 Mar 2002
import heapq as hq
class priorityDictionary(dict):
    def __init__(self):
        self.__heap = []
        dict.__init__(self)
    def smallest(self):
        heap = self.__heap
        while heap[0][1] not in self or self[heap[0][1]] != heap[0][0]:
            hq.heappop(heap)
        return heap[0][1]
    def __iter__(self):
        def iterfn():
            while len(self) > 0:
                x = self.smallest()
                yield x
                del self[x]
        return iterfn()
    def __setitem__(self,key,val):
        dict.__setitem__(self,key,val)
        heap = self.__heap
        if len(heap) > 2 * len(self):
            self.__heap = [(v,k) for k,v in self.iteritems()]
            hq.heapify(self.__heap)
        else:
            hq.heappush(heap, (val,key))

# adapted from http://code.activestate.com/recipes/119466/ (r1)
# Dijkstra's algorithm for shortest paths
# David Eppstein, UC Irvine, 4 April 2002
def Dijkstra(G,start,end=None):
    """
    Find shortest paths from the start vertex to all
    vertices nearer than or equal to the end.

    The input graph G is assumed to have the following
    representation: A vertex can be any object that can
    be used as an index into a dictionary.  G is a
    dictionary, indexed by vertices.  For any vertex v,
    G[v] is itself a dictionary, indexed by the neighbors
    of v.  For any edge v->w, G[v][w] is the length of
    the edge.  This is related to the representation in
    <http://www.python.org/doc/essays/graphs.html>
    where Guido van Rossum suggests representing graphs
    as dictionaries mapping vertices to lists of neighbors,
    however dictionaries of edges have many advantages
    over lists: they can store extra information (here,
    the lengths), they support fast existence tests,
    and they allow easy modification of the graph by edge
    insertion and removal.  Such modifications are not
    needed here but are important in other graph algorithms.
    Since dictionaries obey iterator protocol, a graph
    represented as described here could be handed without
    modification to an algorithm using Guido's representation.

    Of course, G and G[v] need not be Python dict objects;
    they can be any other object that obeys dict protocol,
    for instance a wrapper in which vertices are URLs
    and a call to G[v] loads the web page and finds its links.
    
    The output is a pair (D,P) where D[v] is the distance
    from start to v and P[v] is the predecessor of v along
    the shortest path from s to v.
    
    Dijkstra's algorithm is only guaranteed to work correctly
    when all edge lengths are positive. This code does not
    verify this property for all edges (only the edges seen
    before the end vertex is reached), but will correctly
    compute shortest paths even for some graphs with negative
    edges, and will raise an exception if it discovers that
    a negative edge has caused it to make a mistake.
    """

    D = {}  # dictionary of final distances
    P = {}  # dictionary of predecessors
    Q = priorityDictionary()   # est.dist. of non-final vert.
    Q[start] = 0
    
    for v in Q:
        D[v] = Q[v]
        if v == end: break
        
        for w in G[v]:
            wLength = D[v] + G[v][w]
            if w in D:
                if wLength < D[w]:
                    raise ValueError, "Dijkstra: found better path to already-final vertex"
            elif w not in Q or wLength < Q[w]:
                Q[w] = wLength
                P[w] = v
    
    return (D,P)
            
def shortestPath(G,start,end):
    """
    Find a single shortest path from the given start vertex
    to the given end vertex.
    The input has the same conventions as Dijkstra().
    The output is a list of the vertices in order along
    the shortest path.
    """

    D,P = Dijkstra(G,start,end)
    Path = []
    while 1:
        Path.append(end)
        if end == start: break
        end = P[end]
    Path.reverse()
    return Path
## end of http://code.activestate.com/recipes/119466/ }}}

def setup(infile):
    #C = {}
    return locals()

def reader(testcase, infile, C=None, **ignore):
    #N = int(infile.next())
    #P = map(int, infile.next().split())
    I = map(int, infile.next().split())
    #T = infile.next().split()
    #S = [infile.next().strip() for i in range(N)]
    return locals()

def solver(testcase, N=None, P=None, I=None, T=None, S=None, C=None, **ignore):
    #import collections as co
    #import functools32 as ft
    import itertools as it
    #import operator as op
    #import math as ma
    #import re
    #import numpypy as np
    #import scipy as sp
    #import networkx as nx

    end = tuple(I)

    start = (0, 0)
    D = {}  # dictionary of final distances
    P = {}  # dictionary of predecessors
    Q = priorityDictionary()   # est.dist. of non-final vert.
    Q[start+('K',)] = 1
    
    for v in Q:
        #print v, Q[v]
        D[v] = Q[v]
        if v[:2] == end: break
        
        G = {v: [(-1,0,'W'), (+1,0,'E'),(0,-1,'S'),(0,+1,'N')]}
        for i, d in enumerate(G[v]):
            G[v][i] = (Q[v] * d[0] + v[0], Q[v] * d[1] + v[1], d[2])
        for w in G[v]:
            #print '-', w
            if abs(w[0]) > 100 or abs(w[1]) > 100:
                continue
            wLength = D[v] + 1
            if w in D:
                if wLength < D[w]:
                    raise ValueError, "Dijkstra: found better path to already-final vertex"
            elif w not in Q or wLength < Q[w]:
                Q[w] = wLength
                P[w] = v
    #print P
    end = v
    Path = ""
    while 1:
        Path += end[2]
        if end[:2] == start[:2]: break
        end = P[end]

    return 'Case #%s: %s\n' % (testcase, Path[:-1][::-1])

if __name__ == '__main__':
    import sys
    T = int(sys.stdin.next())
    common = setup(sys.stdin)
    for t in xrange(1, T+1):
        sys.stdout.write(solver(**reader(t, **common)))
