#! /usr/bin/python

import math

cons = "bcdfghjklmnpqrstvwxyz"

def run():
  (name, n) = raw_input().split()
  n = int(n)

  first = 0
  curr = 0
  count = 0

  l = len(name)
  for i in xrange(l):
    c = name[i]
    if c in cons:
      curr += 1
    else:
      curr = 0

    if curr >= n:
      count += (i-n-first+2)*(l-i)
      first = i-n+2

  return count

cases = int(raw_input())
for case in range(cases):
  print "Case #%d: %s"%(case+1, run())


