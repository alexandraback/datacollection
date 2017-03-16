import math
import sys
i = 1
dat = sys.stdin.readlines()
for l in dat[1:]:
  (r,t) = map(int, l.split(" "))
  a = 2*r-1
  q = math.sqrt(a*a + 8*t)
  ans = (-a + q)/4.0
  #print ans
  n = int(ans+1000)
  while t < (2*r*n + 2*n*n - n):
    n -= 1
  print "Case #"+str(i)+": "+str(n)
  i += 1


