#!/usr/bin/env python
#
# Copyright 2013 Super-Magician Inc. All Rights Reserved.

"""Google Code Jam 2013 Qualification - Problem A (Tic-Tac-Toe-Tomek)."""

__author__ = "mqian@caltech.edu (Mike Qian)"

from itertools import dropwhile, takewhile
import sys


CHECK_POS = [
    ((0, 0), (0, 1), (0, 2), (0, 3)),
    ((1, 0), (1, 1), (1, 2), (1, 3)),
    ((2, 0), (2, 1), (2, 2), (2, 3)),
    ((3, 0), (3, 1), (3, 2), (3, 3)),
    ((0, 0), (1, 0), (2, 0), (3, 0)),
    ((0, 1), (1, 1), (2, 1), (3, 1)),
    ((0, 2), (1, 2), (2, 2), (3, 2)),
    ((0, 3), (1, 3), (2, 3), (3, 3)),
    ((0, 0), (1, 1), (2, 2), (3, 3)),
    ((0, 3), (1, 2), (2, 1), (3, 0))
]


def main(args):
  with sys.stdin as f:
    num_cases = int(f.readline())
    for case in xrange(num_cases):
      solved = False
      full = True
      board = [None] * 4
      for i in xrange(4):
        board[i] = list(f.readline().strip())
        if "." in board[i]:
          full = False
      f.readline()
      for positions in CHECK_POS:
        data = [board[i][j] for (i, j) in positions]
        for player in ("X", "O"):
          if data.count(player) == 4 or ("T" in data and data.count(player) == 3):
            print "Case #%d: %s won" % (case+1, player)
            solved = True
            break
        if solved: break
      if solved: continue
      if not solved and full:
        print "Case #%d: Draw" % (case+1)
      else:
        print "Case #%d: Game has not completed" % (case+1)


if __name__ == "__main__":
  main(sys.argv[1:])