#!/usr/bin/env python
#
# Copyright 2013 Super-Magician Inc. All Rights Reserved.

"""Google Code Jam 2013 Qualification - Problem B (Lawnmower)."""

__author__ = "mqian@caltech.edu (Mike Qian)"

from itertools import dropwhile, takewhile
import sys


def main(args):
  with sys.stdin as f:
    num_cases = int(f.readline())
    for case in xrange(num_cases):
      invalid = False
      rows, cols = map(int, f.readline().split())
      lawn = [None] * rows
      row_max = {}
      col_max = {}
      for i in xrange(rows):
        lawn[i] = map(int, f.readline().split())
        row_max[i] = max(lawn[i])
      for j, col in enumerate(zip(*lawn)):
        col_max[j] = max(col)
      for i in xrange(rows):
        for j in xrange(cols):
          val = lawn[i][j]
          if not (val == row_max[i] or val == col_max[j]):
            invalid = True
            break
        if invalid:
          break
      print "Case #%d: %s" % (case+1, "NO" if invalid else "YES")


if __name__ == "__main__":
  main(sys.argv[1:])
