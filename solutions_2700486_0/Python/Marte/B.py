import sys
import string
import bisect
inp = sys.stdin

T = int(inp.readline())
for cas in xrange(1, T + 1):
  print "Case #%d:" % cas,
  N, X, Y = map(int, inp.readline().split())
  X = abs(X)
  D = (X + Y)/2
  s = 2*D*D - D
  if X == 0:
    s += 4*D+1
    if N >= s:
      prob = 1.0
    else:
      prob = 0.0
  else:
    l = N - s
    if l < Y + 1:
      prob = 0.0
    elif l >= Y + 1 + 2*D:
       prob = 1.0
    else:
      prob = 0.0
      for i in xrange(Y+1, l+1):
        prob += 1.0 / (2**min(2*D, i))
  print prob
