#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys

def solve(f):
  #parse
  r, c, w = [int(x) for x in f.readline().strip().split()]

  find = c/w
  hone = w-1 if (c % w == 0) else w
  
  #print r, c, w
  #print find
  #print hone

  return find * r + hone

total = None
count = 0
f = sys.stdin
while f:
  if not total:
    total = int(f.readline().strip())
    continue
  elif count < total:
    count += 1
    print "Case #%d: %s" % (count, solve(f))
  else:
    break

if count < total:
  print "Wrong number of test cases"
  sys.exit(0)

