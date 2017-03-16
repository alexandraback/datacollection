#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys
import random

def solve(t):
  #print t
  counts = {}
  for i in t:
    for j in i:
      counts[j] = counts.get(j, 0) + 1

  in_final = set()
  for i in counts.keys():
    if counts[i] % 2 == 1:
      in_final.add(i)    

  return " ".join([str(x) for x in sorted(list(in_final))])

total = None
count = 0
f = sys.stdin

count = None
length = None
tests = []
test = []
for line in sys.stdin:
  if not count:
    count = int(line.strip())
    continue
  elif not length:
    length = int(line.strip())
    test = []
  else:
    n = [int(x) for x in line.strip().split()]
    test.append(n)
    if len(test) == length*2 - 1:
      tests.append(test)
      length = None

if count != len(tests):
  print "Wrong number of test cases"
  sys.exit(0)

counter = 0
for t in tests:
  counter += 1
  #print t
  print "Case #%d: %s" % (counter, solve(t))
  #sys.exit()



