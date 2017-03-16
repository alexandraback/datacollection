#!/usr/bin/python

import sys

def A(r, k):
  return 2*k*r + 2*k*k - k


def max_k(r, M):
  m = A(r, 1)
  if m > M:
    return 0
  m = A(r, 2*10**18)
  if m <= M:
    return 2*10**18
  k0 = 1
  k1 = 2*10**18
  while k0 + 1 < k1:
    med = (k0 + k1)/2
    m = A(r, med)
    if m <= M:
      k0 = med
    else:
      k1 = med
  return k0


T = int(sys.stdin.readline().strip())
for c in xrange(1, T + 1):
  r, t = [int(x) for x in sys.stdin.readline().strip().split()]
  m = max_k(r, t)
  print "Case #%d: %d" % (c, m)
