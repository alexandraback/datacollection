#!/usr/bin/python

import sys

def get_path(X,Y,x,y,n):
  # print X,Y,x,y
  if (x==X) and (y==Y):
    return "";

  di = ""
  if x != X: # jump E/W
    d = abs(X-x)
    if X > x:
      nx = x + n
      if abs(X-nx) < d:
        x = nx
        di = "E"
      else:
        x -= n
        di = "W"
    else:
      nx = x - n
      if abs(X-nx) < d:
        x = nx
        di = "W"
      else:
        x += n
        di = "E"
  else: # jump N/S
    d = abs(Y-y)
    if Y > y:
      ny = y + n
      if abs(Y-ny) < d:
        y = ny
        di = "N"
      else:
        y -= n
        di = "S"
    else:
      ny = y - n
      if abs(Y-ny) < d:
        y = ny
        di = "S"
      else:
        y += n
        di = "N"
  return di + get_path(X,Y,x,y,n+1)

T = int(sys.stdin.readline())
for t in range(T):
  # print >> sys.stderr, "Test: %d" % (t+1)
  toks = sys.stdin.readline().strip().split()
  X = int(toks[0])
  Y = int(toks[1])

  # print X,Y

  P = get_path(X,Y,0,0,1)

  print "Case #%d: %s" % (t+1,P)

