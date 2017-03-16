#!/usr/bin/python

import sys

def toInt(a):
  return int(a)

import sys

N = int(sys.stdin.readline())
#print N
for test in range(0, N):
  t = sys.stdin.readline().rstrip('\n').split()
  N = int(t[0]);
  s = map(lambda x: int(x), t[1:])

#  print N
#  print s
  X = 0
  S = []
  for i in range(N):
    X += s[i]
    S.append( (i, s[i]) )
  S.sort(lambda x,y: x[1] - y[1])

  S.append( (N+1, 100*10000) )
  m = []
  x = X
  T = 0
  for i in range(N):
    delta = S[i+1][1] - S[i][1]
    if x >= delta*(i+1):
      x = x - delta*(i+1)
    else:
      T = float(x)/(i+1) + S[i][1]
      break
  result = "Case #%d:" % (test+1)
  for i in range(N):
    if T > s[i]:
      result += " %.6f" % ((T-s[i])/X*100)
    else:
      result += " %.6f" % (0.0)
  print result
