#!/usr/bin/env python
import sys


def small(X, Y):
  s = 'WE' * X if X > 0 else 'EW' * (-X)
  s += 'SN' * Y if Y > 0 else 'NS' * (-Y)
  return s

def check(X, Y, sln):
  x = y = 0
  k = 1
  for s in sln:
    if s == 'W':
      x -= k
    elif s == 'E':
      x += k
    elif s == 'S':
      y -= k
    elif s == 'N':
      y += k
    k += 1
  assert x == X
  assert y == Y


# process all tests
T = int(sys.stdin.readline())
for i in range(T):
  X, Y = map(int, sys.stdin.readline().strip().split())
  sln = small(X, Y)
  check(X, Y, sln)
  print 'Case #%d: %s' % (i + 1, sln)
