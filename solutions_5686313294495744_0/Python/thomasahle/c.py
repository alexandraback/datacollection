import sys
read = lambda t=int: list(map(t,sys.stdin.readline().split()))
array = lambda *ds: [array(*ds[1:]) for _ in range(ds[0])] if ds else 0

from collections import defaultdict

def main():
   T, = read()
   for testCase in range(T):
      N, = read()
      left, right = set(), set()
      graph = defaultdict(set)
      for i in range(N):
         first, second = read(str)
         graph[first].add(second)
         left.add(first)
         right.add(second)
      M, A, B = matching(graph)
      #print(len(left), len(right), len(M))
      #print(M)
      res = N - (len(left) + len(right) - len(M))
      print('Case #{}: {}'.format(testCase+1, res))

# By D. Eppstein
def matching(graph):
   """
    Find maximum cardinality matching of a bipartite graph (U,V,E).
    The input format is a dictionary mapping members of U to lists
    of their neighbors in V.  The output is a triple (M,A,B) where M is a
    dictionary mapping members of V to their matches in U, A is the part
    of the maximum independent set in U, and B is the part of the MIS in V.
    The same object may occur in both U and V, and is treated as two
    distinct vertices if this happens.
   """

   # initialize greedy matching (redundant, but faster than full search)
   matching = {}
   for u in graph:
      for v in graph[u]:
         if v not in matching:
            matching[v] = u
            break

   while True:
      # structure residual graph into layers
       # pred[u] gives the neighbor in the previous layer for u in U
       # preds[v] gives a list of neighbors in the previous layer for v in V
       # unmatched gives a list of unmatched vertices in final layer of V,
       # and is also used as a flag value for pred[u] when u is in the first layer
       preds = {}
       unmatched = []
       pred = {u:unmatched for u in graph}
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
                      return True
          return False

       for v in unmatched:
          recurse(v)

main()
