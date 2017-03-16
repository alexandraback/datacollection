def guess(n,m,prods):
  must = {}
  for k in prods:
    for p in range(1,n*3):
      if k % (7**p) == 0: must[7] = max(must.get(7,0),p)
      if k % (5**p) == 0: must[5] = max(must.get(5,0),p)
      if k % (3**p) == 0: must[3] = max(must.get(3,0),p)
      if k % (2**p) == 0: must[2] = max(must.get(2,0),p) # Must refers to the abstract factors
    if must.get(2,0) + must.get(3,0) + must.get(5,0) + must.get(7,0) == n: return must
  p = 1
  for k in prods: p *= k
  op = int(p ** (1./n))
  fac = {}
  for v in [2,3,5,7]:
    while p%v == 0:
      #print p,v,prods
      fac[v] = fac.get(v,0)+1
      p /= v
  s = 0
  pfac = 1
  for v in fac: # Average number of each
    fac[v] = max(int(fac[v] * 1.0 / len(prods) + 0.5),must.get(v,0))
    s += fac[v]
    pfac *= v**fac[v]
  if s <= n:
    mval = max(2,min(m,int((op / pfac)**(1./n))))
    fac[2] = fac.get(mval,0) + (n-s)
    return fac
  while s > n:
    if fac.get(2,0) > 1:
      fac[4] = fac.get(4,0)+1
      fac[2] = fac.get(2,0)-2
      s -= 1
    elif fac.get(2,0) > 0 and fac.get(3,0) > 0:
      fac[6] = fac.get(6,0)+1
      fac[2] = fac.get(2,0)-1
      fac[3] = fac.get(2,0)-1
      s -= 1
    elif fac.get(2,0) > 2:
      fac[8] = fac.get(8,0)+1
      fac[2] = fac.get(2,0)-3
      s -= 1
    else: s -= 1 # Give up
  return fac

tc = int(raw_input())

for i in range(tc):
  r,n,m,k = [int(x) for x in raw_input().split(' ')]
  print "Case #%s:" % str(i+1)
  for j in range(r):
    vs = [int(x) for x in raw_input().split(' ')]
    ans = guess(n,m,vs)
    ansstr = ''
    for x in ans: ansstr += str(x) * ans[x]
    print ansstr
