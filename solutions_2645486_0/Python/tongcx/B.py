from sys import stdin
from gurobipy import *

T = int(stdin.readline())
for _ in xrange(1, T+1):
  E, R, N = map(int, stdin.readline().split())
  R = min(E,R)
  v = map(int, stdin.readline().split())
  v.append(0)
  m = Model()
  m.modelsense = -1
  m.params.outputflag = 0
  f = [m.addVar(0, E-R, v[i]-v[i+1]) for i in xrange(N)]
  m.update()
  for i in xrange(N-1): m.addConstr(f[i+1] >= f[i]-R)
  m.optimize()
  print 'Case #%d: %d' % (_, int(m.objval+R*sum(v)))
