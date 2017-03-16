def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

_T = readint()
for _t in range(_T):
  print 'Case #%i:'%(_t+1),
  
  C, F, X = readarray(float)
  
  N = 100000
  T = [0.0]*N
  cur = 2.0
  for i in range(1, N):
    T[i] = T[i-1]+C/cur
    cur += F
  
  G = [0.0]*N
  cur = 2.0
  for i in range(N):
    G[i] = T[i] + X/cur
    cur += F
  print min(G)
