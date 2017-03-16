#!/usr/bin/env python
import sys

data = sys.stdin.readlines()
T = int(data[0])

def fsum(a):
  b = a//4-1
  res = 2*b*(b+1)
  res += (a%4)*(b+1)
  return res

def solve(r, t):
  lo, hi = 1, t
  while ((hi-lo)>1):
    m = (lo+hi)//2
    val = fsum(2*r+4*m+1)-fsum(2*r+1)
    if (val > t):
      hi = m
    else:
      lo = m;
  return lo

index = 1
for line in data[1:]:
  r, t = line.split()
  r, t = int(r), int(t)
  print("Case #" + str(index) + ": " + str(solve(r, t)))
  index += 1
