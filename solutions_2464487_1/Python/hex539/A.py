#!/usr/bin/env python
from math import *

for tst in xrange(1,int(raw_input())+1):
  r,t = map(int,raw_input().split())
  r = (r+1)

  lef = 0
  rad = 2 ** 100
  while rad >= 1:
    mid = lef + rad
    need = ((r+mid*2-2)*((r+mid*2-2)+2)) - (r*(r-2)) - mid * 2
    if need <= t * 2:
      lef = mid
    rad /= 2

  print "Case #" + str(tst) + ": " + str(lef)
