def bipartiteMatch(graph):
  # Taken from David Eppstein, UC Irvine, 27 Apr 2002
  matching = {}
  for u in graph:
    for v in graph[u]:
      if v not in matching:
        matching[v] = u
        break
  
  while 1:
    preds = {}
    unmatched = []
    pred = dict([(u,unmatched) for u in graph])
    for v in matching:
      del pred[matching[v]]
    layer = list(pred)
    
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
    
    if not unmatched:
      unlayered = {}
      for u in graph:
        for v in graph[u]:
          if v not in preds:
            unlayered[v] = None
      return (matching,list(pred),list(unlayered))

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
    
from collections import defaultdict
def solve(N,A):
    X,Y = zip(*A)
    sX,sY = set(X),set(Y)
    G = defaultdict(list)
    for i,j in A:
        G[(0,i)].append((1,j))
    z= bipartiteMatch(G)[0]
    real = len(z)
    for k in z:
      v = z[k]
      for i,j in [k,v]:
        if i == 0:
          sX.discard(j)
        else:
          sY.discard(j)
    real += len(sX) + len(sY)
    return N - real

########
fo = open('out.txt','w')
with open('in.txt','r') as fi:
    rr = lambda: fi.readline().strip()
    rrI = lambda: int(rr())
    rrM = lambda: map(int,rr().split())
    for tc in xrange(rrI()):
        N = rrI()
        A = [rr().split() for _ in xrange(N)]
        zetaans = solve(N,A)
        zeta = "Case #%i: "%(tc+1) + str(zetaans)
        print zeta
        fo.write(zeta+'\n')
fo.close()
