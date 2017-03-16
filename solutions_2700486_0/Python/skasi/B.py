#!/usr/bin/python2.5
#-*- coding: utf-8 -*-

# Pychecker options
__pychecker__ = 'no-callinit no-classattr'

# External imports
import sys

# Internal imports (if any)

def getline():
  return sys.stdin.next().rstrip()

def backtracking(N, point, h, l, r, prob):
  if N == 0:
    return 0.0

  # print 'h', h, 'l', l, 'r', r

  if l == r == h - 1: # Centered
    # print 'Centered %d, %d' % (0, h - 1)
    if (0, h - 1) == point:
      return prob
    return backtracking(N - 1, point, h + 2, 0, 0, prob)
  
  if h - 1 not in (l, r):
    prob /= 2.0
  
  value = 0.0

  if l == h - 1 or not r == h - 1: # Falling right
    # print 'Fall right %d, %d' % (h - r - 1, r)
    if (h - r - 1, r) == point:
      value += prob
    else:
      value += backtracking(N - 1, point, h, l, r + 1, prob)

  if r == h - 1 or not l == h - 1: # Falling left
    # print 'Fall left %d, %d' % (- h + l + 1, l)
    if (- h + l + 1, l) == point:
      value += prob
    else:
      value += backtracking(N - 1, point, h, l + 1, r, prob)

  return value

def challenge():
  N, X, Y = map(int, getline().split())

  print backtracking(N, (X, Y), 1, 0, 0, 1.0)

# Main entry point
if __name__ == '__main__':
  testcases = int(getline())

  for testcase in xrange(1, testcases + 1):
    print 'Case #%d:' % (testcase, ),
    challenge()

