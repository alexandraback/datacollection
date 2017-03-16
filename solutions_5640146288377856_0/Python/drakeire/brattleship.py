#!/usr/bin/env python

import sys

def main():
  fi = sys.stdin
  fo = sys.stdout
  caseCount = int(fi.readline().strip())
  for i in range(1, caseCount+1):
    r, c, w = readInput(fi)
    solution = solve(r, c, w)
    displayAndClear(fo, i, solution)

def readInput(f):
  r, c, w = [int(arg) for arg in f.readline().split()]
  return r, c, w

def displayAndClear(f, i, solution):
  f.write('Case #%d: %d\n' % (i, solution))
  f.flush()

def solve(r, c, w):
  # scan
  columnsToScan = c/w
  total = columnsToScan * r

  # find the correct side.
  if c % w != 0:
    total += 1 # miss

  # fire rest 
  total += w - 1

  return total

if __name__ == '__main__':
  main()

