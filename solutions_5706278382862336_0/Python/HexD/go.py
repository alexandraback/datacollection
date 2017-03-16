#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# @author: Danilo J. S. Bellini
"""
Part Elf
"""

import sys

def elf_ancestor(P, Q, max_ancestors=40):
  k, remain = divmod(P * 2 ** max_ancestors, Q)

  if remain != 0:
    raise ValueError("Impossible")

  answer = max_ancestors
  while k >= 2:
    k //= 2
    answer -= 1
  return answer

# I/O processing
fname = sys.argv[1]
with open(fname, "r") as fin:
  with open("output.txt", "w") as fout:
    T = int(fin.readline())
    for case in range(1, T + 1):
      data = map(int, fin.readline().split("/"))
      try:
        result = elf_ancestor(*data)
      except ValueError:
        result = "impossible"
      fout.write("Case #{}: {} \n".format(case, result))
