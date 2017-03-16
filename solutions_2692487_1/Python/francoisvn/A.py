#!/usr/bin/python

import sys

def getops(N,ops,A,motes):
  # print N,ops,A,motes
  if ops >= N: # could have just removed all the motes
    # print "limit!"
    return N
  if len(motes) == 0:
    # print "ops",ops
    return ops

  m = motes.pop()

  if A > m:
    # print "eat",A,m,motes
    A += m
    o = getops(N,ops,A,motes)
    motes.append(m)
    return o
  else:
    d = m - A + 1 # size mote we would need to eat to be able to eat m
    b = A - 1 # max mote that can be eaten
    if A > d: # add and eat it
      # print "eatadd",A,b,m,motes
      A += b
      A += m
      o = getops(N,ops+1,A,motes)
      motes.append(m)
      return o
    else:
      # try removal
      # print "rmv",A,m,motes
      o1 = getops(N,ops+1,A,motes)
      # try addition
      # print "add",A,b,m,motes
      A += b
      n = 1
      while A <= m:
        b = A - 1 # max mote that can be eaten
        A += b
        n += 1
      A += m
      o2 = getops(N,ops+n,A,motes)
      motes.append(m)
      return min(o1,o2)

T = int(sys.stdin.readline())
for t in range(T):
  # print >> sys.stderr, "Test: %d" % (t+1)
  toks = sys.stdin.readline().strip().split()
  A = int(toks[0])
  N = int(toks[1])

  toks = sys.stdin.readline().strip().split()
  motes = []
  for tt in toks:
    motes.append(int(tt))
  motes.sort()
  motes.reverse()

  # print A,N
  # print motes

  ops = N
  if A > 1:
    ops = getops(N,0,A,motes)

  print "Case #%d: %d" % (t+1,ops)

