#!/usr/bin/python2

from sys import stdin
from array import *

def count(n, a, b):
  l = str(n)
  k = [n]
  for i in range(1,len(l)):
    ii = int(l[i:]+l[:i])
    if a <= ii <= b:
      k.append(ii)
  return set(k)

def solve(a, b):
  counted = [False] * (b-a+2)
  nn = 0
  for i in range(a, b+1):
    if counted[i-a]:
      continue
    else:
      k = count(i, a, b)
      if not k:
        continue

      m = min(k)
      if counted[m-a]:
        continue
      else:
        nn += (len(k)*(len(k)-1))/2
        for j in k:
          counted[j-a] = True

  return nn

n = int(stdin.readline())
for i in xrange(1, n+1):
  a, b = [int(j) for j in stdin.readline().strip().split()]

  sol = solve(a, b)
  print 'Case #%d: %d' % (i, sol)
