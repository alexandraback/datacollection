from sys import stdin
from math import floor

def Q(a,b):
  return a/b

T = int(next(stdin))
for t in xrange(1,T+1):
  C, F, X = map(float, next(stdin).split(" "))
  if X <= C:
    m = 0
  else:
    m = int(Q(X*F-2*C,F*C))
  time = sum(Q(C,2+k*F) for k in xrange(0,m))+Q(X,2+m*F)
  print "Case #%d: %.7f" %  (t, time)
