#!/usr/bin/env python

import sys
from math import floor, ceil, sqrt

def main():
  f = sys.stdin
  caseCount = int(f.readline().strip())
  for i in range(caseCount):
    e, r, n = [int(arg) for arg in f.readline().split()]
    v = [int(arg) for arg in f.readline().split()]
    print 'Case #%i: %i' % (i+1, findMaxGain(e, r, n, v))
    pass

def findMaxGain(e, r, n, v):
  vMax = max(v)
  gain = 0
  for vi in v:
    if vi < vMax:
      spent = r / vi if r < e else e
    else:
      spent = e
    gain += spent*vi
  return gain

if __name__ == '__main__':
  main()
