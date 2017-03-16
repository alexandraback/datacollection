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

def obsah(t):
  c = t**2
  d = (t-1)**2
  return( c - d )
 
for case in range(1, T+1):
  r, t = [int(x) for x in input().split()]
  vol = r+1
  act = t
  ctr = 0
  while (act >= obsah(vol)):
    ctr+=1
    act -= obsah(vol)
    vol+=2
        
  print("Case #" + str(case) + ": " + str(ctr))

