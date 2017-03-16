import sys
from math import sqrt, floor

T = int(sys.stdin.readline())


for t in range(T):
  smax, si = sys.stdin.readline().split()
  i = 0
  extras = 0
  total = 0
  for i in range(int(smax)):
    if(int(si[i])==0) and (total <= i):
      extras +=1
      total += 1
    else:
      total += int(si[i])
      
  print "Case #%d: %d"%(t+1, extras)