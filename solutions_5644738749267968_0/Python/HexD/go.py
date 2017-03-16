#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on Sat Apr 12 07:47:38 2014
# @author: Danilo J. S. Bellini
"""
Deceitful War
"""

import sys

if sys.version_info.major >= 3:
  map = lambda *args, **kwargs: list(map(*args, **kwargs))

def war(naomi, ken):
  snaomi = sorted(naomi)
  sken = sorted(ken)
  result = 0
  for el in reversed(snaomi):
    if sken[-1] > el:
      sken.pop()
    else:
      result += 1
  return result

def deceitful_war(naomi, ken):
  blocks = {"n": naomi, "k": ken}
  sorted_pairs = sorted(list(enumerate("n" * len(naomi))) +
                        list(enumerate("k" * len(ken))),
                        key = lambda pair: blocks[pair[1]][pair[0]])
  result, remain, loses = 0, 0, 0
  matches = len(naomi)
  for unused, name in sorted_pairs:
    if name == "k":
      result += 1
      remain += 1
    elif remain:
      remain -= 1
    else:
      loses += 1
    if loses + result == matches:
      break
  return result

# I/O processing
fname = sys.argv[1]
with open(fname, "r") as fin:
  with open("output.txt", "w") as fout:
    T = int(fin.readline())
    for case in range(1, T + 1):
      N = int(fin.readline())
      naomi = map(float, fin.readline().split())
      ken = map(float, fin.readline().split())
      results = deceitful_war(naomi, ken), war(naomi, ken)
      fout.write("Case #{}: {} {}\n".format(case, *results))
