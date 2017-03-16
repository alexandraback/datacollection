#!/usr/bin/env python

import sys
from itertools import product
import re

def main():
  fi = sys.stdin
  fo = sys.stdout
  caseCount = int(fi.readline().strip())
  for i in range(1, caseCount+1):
    keyboard, goal, k, l, s = readInput(fi)
    solution = solve(keyboard, goal, k, l, s)
    displayAndClear(fo, i, solution)

def readInput(f):
  k, l, s = [int(arg) for arg in f.readline().split()]
  keyboard = f.readline().strip()
  goal = f.readline().strip()
  return keyboard, goal, k, l, s

def displayAndClear(f, i, solution):
  f.write('Case #%d: %.7f\n' % (i, solution))
  f.flush()

def solve(keyboard, goal, k, l, s):
  maxMatch = -1
  
  totalMatchCount = 0
  strCount = 0
  for prod in product(keyboard, repeat=s):
    candidateStr = ''.join(prod)
    strCount += 1
    matchCount = findAll(candidateStr, goal)
    maxMatch = max(maxMatch, matchCount)
    totalMatchCount += matchCount
    
  return maxMatch - (float(totalMatchCount) / strCount)

def findAll(candidate, goal):
  #return [m.start() for m in re.finditer(goal, full)] #WRONG

  start = 0
  l = len(candidate)
  count = 0
  while start < l:
    loc = candidate.find(goal, start)
    if loc != -1:
      count += 1
      start = loc + 1
    else:
      break

  return count

if __name__ == '__main__':
  main()

