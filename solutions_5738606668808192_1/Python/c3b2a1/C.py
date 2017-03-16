#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import math

def calc(v):
  s = "{:b}".format(v)
  divlist = [s]
  for base in range(2, 11):
    rs = 0
    for ch in s:
      rs = rs * base
      if ch=='1':
        rs += 1
 
    div = 3
    while div< math.sqrt(rs)+1 and div<1e3 and rs%div!=0:
      div +=2
    if div==rs or rs%div != 0:
      return False
    divlist.append(div)

  print " ".join(map(str, divlist))
  return True


t = int(sys.stdin.readline())
for tc in range(1, t + 1):
  N, J = [int(s) for s in sys.stdin.readline().split(" ")]
  cval = (1<<(N-1))+1
  print("Case #{}:".format(tc))
  while J>0:
    if calc(cval):
      J -= 1
    cval += 2
  
