#!/usr/bin/env python
from math import sqrt
from math import floor

def valid(num, r, t):
  x = 2 * num * num + (2 * r - 1) * num
  return  x<= t

def solve():
  tups = raw_input().split()
  r = long(tups[0])
  t = long(tups[1])
  b = (2 * r - 1) * (2 * r - 1) + 8 * t
  s = (sqrt(b) + 1 - 2 * r) / 4.0
  a1 = long(floor(s))
  for i in xrange(a1 + 1, 0, -1):
    if valid(i, r, t):
      return i
  return 1
  
def main():
  cases = int(raw_input())
  for case in range(cases):
    case = case + 1
    print "Case #%d: %d" % (case, solve())

main()
