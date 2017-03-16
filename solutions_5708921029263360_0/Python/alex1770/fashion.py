import sys

def weight(x):
  if x==0: return 0
  return (x&1)+weight(x>>1)

def thing(J,P,S,K):
  assert J<=P and P<=S and S<=3
  if K>=3:
    print J*P*S
    for j in range(J):
      for p in range(P):
        for s in range(S):
          print j+1,p+1,s+1
    return
  if J==3 and K==2:
    print 18
    print """1 1 1
1 1 3
1 2 1
1 2 2
1 3 2
1 3 3
2 1 1
2 1 2
2 2 2
2 2 3
2 3 1
2 3 3
3 1 2
3 1 3
3 2 1
3 2 3
3 3 1
3 3 2"""
    return
  Sps=[]
  for ps in range(1<<(P*S)):
    Np=[0]*P;Ns=[0]*S
    for p in range(P):
      for s in range(S):
        v=(ps>>(p*S+s))&1
        Np[p]+=v
        Ns[s]+=v
    if max(Np)<=K and max(Ns)<=K: Sps.append((ps,weight(ps)))
  nps=len(Sps)
  mx=-1
  for j in range(nps**J):
    Nps=[0]*(P*S)
    j0=j;t=0
    for k in range(J):
      (x,w)=Sps[j0%nps];t+=w
      for l in range(P*S): Nps[l]+=x&1;x>>=1
      j0=j0//nps
    if max(Nps)<=K and t>mx: mx=t;j1=j
  print mx
  for k in range(J):
    (x,w)=Sps[j1%nps]
    for l in range(P*S):
      if x&1:
        print k+1,l/S+1,l%S+1
      x>>=1
    j1=j1//nps

T=int(sys.stdin.readline())
for case in range(1,T+1):
  [J,P,S,K]=[int(y) for y in sys.stdin.readline().strip().split()]
  print "Case #%d:"%case,;thing(J,P,S,K)
