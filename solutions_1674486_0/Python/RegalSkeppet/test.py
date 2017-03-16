#!/usr/bin/python

import sys

testCases = int(sys.stdin.readline())

def next(classes, c, visited):
  visits = set(classes[c])
  if visits & set(visited):
    return True
  visited.extend(visits)
  for c2 in visits:
    if next(classes, c2, visited):
      return True
  return False


for testCase in range(testCases):
  classes = {}
  for c in range(int(sys.stdin.readline())):
    c = c + 1
    line = [int(floor) for floor in sys.stdin.readline().split(' ')]
    inheritCount = line[0]
    inherits = line[1:]
    classes[c] = inherits
  diamond = "No"
  for c in classes.keys():
    if next(classes, c, []):
      diamond = "Yes"
      break
  print "Case #{0}: {1}".format(testCase + 1, diamond)

