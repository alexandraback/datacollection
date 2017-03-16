#!/usr/bin/python

import sys


def solve(a, b, c, K, mode):
  outfits = []
  u = 1
  v = 0
  w = 1
  it = 0
  while w <= c:
    v += 1
    if v > b:
      u += 1
      v = 1
    if u > a:
      break

    for i in xrange(K):
      if i+w > c:
        break
      if mode == 1:
        outfits.append("%d %d %d"%(u, v, i+w))
      elif mode == 2:
        outfits.append("%d %d %d"%(v, i+w, u))
      else:
        outfits.append("%d %d %d"%(i+w, u, v))

    it += 1
    if it == K:
      w += min(c,K)
      it = 0

  return outfits

def case(J, P, S, K):
  rc = [solve(J, P, S, K, 1), solve(S, J, P, K, 2), solve(P, S, J, K, 3)]
  if len(rc[0]) == max(map(len, rc)):
    r = rc[0]
  elif len(rc[1]) == max(map(len, rc)):
    r = rc[1]
  else:
    r = rc[2]

  return '%d\n'%len(r)+'\n'.join(r)


f = open(sys.argv[1])
T = int(f.readline())
for i in xrange(T):
  (J, P, S, K) = map(int, f.readline().split())
  print "Case #%d: %s"%(i+1, case(J, P, S, K))

