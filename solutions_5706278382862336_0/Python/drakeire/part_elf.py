#!/usr/bin/env python

import sys

def main():
  fi = sys.stdin
  fo = sys.stdout
  caseCount = int(fi.readline().strip())
  for i in xrange(1, caseCount+1):
    p, q = readInput(fi)
    level = solve(p, q)
    displayAndClear(fo, i, level)

def readInput(f):
  p, q = [int(arg.strip()) for arg in f.readline().split('/')]
  return p, q

def displayAndClear(f, i, level):
  if level == -1:
    f.write('Case #%d: impossible\n' % i)
  else:
    f.write('Case #%d: %d\n' % (i, level))
  f.flush()

def solve(p, q):
  return isValidRatio(p, q, 0, 40)

def isValidRatio(p, q, level, limit):
  while level < limit: 
    if p == 0:
      return level
    elif p >= q:
      if isValidRatio(p-q, q, level, limit) != -1:
        return level
      else:
        return -1
    p *= 2
    level += 1
  return -1

if __name__ == '__main__':
  main()

