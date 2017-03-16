#!/usr/bin/env python

import sys
from math import floor, ceil, sqrt

_rMax = 1000
#_tMax = pow(10,18)
_tMax = 1000

def main():
  f = sys.stdin
  caseCount = int(f.readline().strip())
  for i in range(caseCount):
    r, t = [int(arg) for arg in f.readline().split()]
    print 'Case #%i: %i' % (i+1, countCircles(r, t))


def countCircles(r, t):
  # n+1 st (n +1) * (2n + 2r + 1) <= t
  minx = 0
  maxx = int(sqrt(_tMax))
  while True:
    mid = (minx+maxx) / 2
    paint = (mid+1) * (2*mid + 2*r + 1)
    if paint > t:
      maxx = mid - 1
    elif paint < t:
      mid2 = mid + 1
      paint2 = (mid2+1) * (2*mid2 + 2*r + 1)
      if paint2 > t:
        return mid + 1
      minx = mid + 1
    else:
      return mid + 1
    #print minx, mid, maxx

if __name__ == '__main__':
  main()

