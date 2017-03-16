#!/usr/bin/python2.5
#-*- coding: utf-8 -*-

# Pychecker options
__pychecker__ = 'no-callinit no-classattr'

# External imports
import math
import sys

# Internal imports (if any)

def getline():
  return sys.stdin.next().rstrip()

def backtracking(motes, A):
  if not motes:
    return 0

  if A > motes[0]:
    return backtracking(motes[1:], A + motes[0])
  elif A > 1:
    return min(
        1 + backtracking(motes, 2 * A - 1), # Adding
        1 + backtracking(motes[1:], A)) # Deleting
  else:
    return 1 + backtracking(motes[1:], A) # Deleting

def challenge():
  A, N = map(int, getline().split())
  motes = sorted(map(int, getline().split()[:N]))

  print backtracking(motes, A)

# Main entry point
if __name__ == '__main__':
  testcases = int(getline())

  for testcase in xrange(1, testcases + 1):
    print 'Case #%d:' % (testcase, ),
    challenge()

