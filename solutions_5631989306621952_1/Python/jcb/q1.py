#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys
import random


def old_solve(s):
  
  if len(s) <= 1:
    return s

  highest = 0
  for i in range(len(s)):
    if s[i] >= s[highest]:
      highest = i

  return s[highest] + solve(s[:highest]) + s[highest+1:]

def solve(s):
  if len(s) <= 1:
    return s

  solution = s[0]

  for c in s[1:]:
    if c >= solution[0]:
      solution = c + solution
    else:
      solution = solution + c

  return solution

total = None
count = 0
f = sys.stdin

count = None
tests = []
for line in sys.stdin:
  if not count:
    count = int(line.strip())
    continue
  else:
    tests.append(line.strip())

if count != len(tests):
  print "Wrong number of test cases"
  sys.exit(0)

counter = 0
for s in tests:
  counter += 1
  #print t
  print "Case #%d: %s" % (counter, solve(s))
  #sys.exit()



