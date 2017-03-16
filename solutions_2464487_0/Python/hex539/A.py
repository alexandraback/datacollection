#!/usr/bin/env python
from math import *

for tst in xrange(1,int(raw_input())+1):
  r,t = map(int,raw_input().split())
  r = (r+1)

  lef = 0
  rad = 2 ** 100
  while rad >= 1:
    mid = lef + rad
    # need = 2.0 * ((r+mid-1)*((r+mid-1)+1)) - 2.0 * (r*(r-1)) - mid
    need = ((r+mid*2-2)*((r+mid*2-2)+2)) - (r*(r-2)) - mid * 2
    # if mid == 1 or mid == 2 or mid == 50:
    #   print mid, need
    if need <= t * 2:
      lef = mid
    rad /= 2

#  r = (r+1) / 2.0
#  res = 0
#  while t >= 4 * r - 1 and res < 10000:
#    t -= 4 * r - 1
#    r += 1
#    res += 1

  print "Case #" + str(tst) + ": " + str(lef)
