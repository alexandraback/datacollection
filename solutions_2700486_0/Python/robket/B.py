#Diamonds
import numpy as np
for c in xrange(int(raw_input())):
  n, x, y = map(int, raw_input().split())
  if (x + y)%2 == 1:
    print "Case #"+str(c+1)+": 0.0"
    continue
  if x < 0:
    base = -x + y + 1 
  elif x > 0:
    base = x + y + 1 
  else:
    base = y + 1 
  full = (base**2 + base) / 2
  empty = ((base-2)**2 + base-2) / 2
  if n < empty or x == 0 and n < full:
    print "Case #"+str(c+1)+": 0.0"
    continue
  if n >= full:
    print "Case #"+str(c+1)+": 1.0"
    continue
  
  #print "Base", base, "empty", empty, "full", full
  # The number of diamonds to make the outer layer
  N = n - empty
  k = y +1 
  #print "N",N,"k", k
  # The number of diamonds to fall on one side must be more than y
  pasc = np.ones((N+1, N+1)) 
  for i in xrange(1, N+1):
    for j in xrange(1, N + 1 - i):
      pasc[i, j] = pasc[i-1, j] + pasc[i, j-1] 
  tot = 0
  for i in xrange(N+1):
    tot += pasc[i, N - i]
  sm = 0
  for i in xrange(k-1):
    sm += pasc[i, N - i] 
  print "Case #"+str(c+1)+":", sm/tot
