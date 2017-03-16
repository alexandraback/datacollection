#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on Sat Apr 12 05:41:34 2014
# @author: Danilo J. S. Bellini
"""
Minesweeper Master
"""

import sys

if sys.version_info.major >= 3:
  zip = lambda *args, **kwargs: list(zip(*args, **kwargs))

def minesweeper(R, C, M):
  if R > C:
    return ["".join(col) for col in zip(*minesweeper(C, R, M))]
  if R * C <= M:
    raise ValueError("Impossible")
  if R == 1:
    return ["c" + "." * (C - M - 1)  + "*" * M]
  if R == C == 2:
    if M == 0:
      return ["c.",
              ".."]
    elif M == 3:
      return ["c*",
              "**"]
    else:
      raise ValueError("Impossible")
  if M >= R:
    return [row + "*" for row in minesweeper(R, C - 1, M - R)]
  result = [list("." * C) for row in range(R)]
  result[0][0] = "c"
  for row in list(reversed(result))[:M]:
    row[-1] = "*"
  if R < M + 2:
    if R == 2 or C < 4:
      raise ValueError("Impossible")
    # C >= R = M + 1
    result[1][-1] = "."
    result[-1][-2] = "*"
  return ["".join(row) for row in result]

# I/O processing
fname = sys.argv[1]
with open(fname, "r") as fin:
  with open("output.txt", "w") as fout:
    T = int(fin.readline())
    for case in range(1, T + 1):
      inputs = map(int, fin.readline().split())
      fout.write("Case #{}:\n".format(case))
      try:
        result = minesweeper(*inputs)
      except ValueError:
        fout.write("Impossible")
      else:
        fout.write("\n".join(result))
      fout.write("\n")
