#!/usr/bin/env python
T = int(input())
"""
  r - vnutorny polomer
  potom strieda 1cm 1cm 1cm 1cm
  obsah kruhu: pi*r^2
  obsah mkruhu: pi*r^2 - pi*(r-1)^2
  1ml paint required
  
"""
import math
pi = math.pi

def res(start, n):
  return (2*n*start - n + n*(n-1)*2)
 
for case in range(1, T+1):
  r, t = [int(x) for x in input().split()]
  vol = r+1
  act = t
  ctr = 0
  n = 1
  ## now binary search
  max = 10**12
  high = 10**14
  low = 0
  x = 10**6
  while(True):
    if (res(r+1, x) == t): 
      break
    if (res(r+1, x) > t):
      high = x
      x = int((x+low)/2)
    else:
      if (res(r+1, x+1) > t):
        break
      else:
        low = x
        x = int( (high + x) / 2)
  ctr = x
 
  print("Case #" + str(case) + ": " + str(ctr))

