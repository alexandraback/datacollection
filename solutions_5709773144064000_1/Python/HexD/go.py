#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Created on Sat Apr 12 05:11:10 2014
# @author: Danilo J. S. Bellini
"""
Cookie Clicker Alpha
"""

from __future__ import division
import sys

def min_duration_to_x(C, F, X, start=2):
  k = 0 # Amount of farms
  past = 0
  while (start + k * F) / (start + (k + 1) * F) < 1 - C / X:
    past += C / (start + k * F)
    k += 1
  return past + X / (start + k * F)

# I/O processing
fname = sys.argv[1]
with open(fname, "r") as fin:
  with open("output.txt", "w") as fout:
    T = int(fin.readline())
    for case in range(1, T + 1):
      inputs = map(float, fin.readline().split())
      result = min_duration_to_x(*inputs)
      fout.write("Case #{}: {:01.7f} \n".format(case, result))
