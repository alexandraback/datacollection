#!/usr/bin/env python

import math
def ri():
  x=''
  while not x:
    x = raw_input().strip()
  return x

fc = math.factorial
def nck(n,k):
  return fc(n)/fc(k)/fc(n-k)


T=int(ri())
for t in xrange(1,T+1):
  n,x,y = map(int,ri().split())
  g = int(math.ceil((n/2.0)**.5-1))
  while (2*g+1)*(g+1) <= n:
    g += 1
  g -= 1
  if abs(x)+y <= 2*g:
    ans = 1.
  elif abs(x)+y > 2*g+2:
    ans = 0.
  elif y == 2*g+2:
    ans = 0.
  else:
    k = n-(2*g+1)*(g+1)
    if y+1 <= k-(2*g+2):
      ans = 1.
    else: #k <= 2*g+2:
      ans = sum(nck(k,i) for i in xrange(y+1,k+1)) * 10000000 // (2**k)
      ans = float(ans)/10000000.0

  print 'Case #%d: %f'%(t,ans)
    

