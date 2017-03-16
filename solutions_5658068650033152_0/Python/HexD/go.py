#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @author: Danilo J. S. Bellini
"""
Enclosure
"""

import sys

def enclosure(N, M, K):
  if K <= 4 or N <= 2 or M <= 2:
    return K

  left = right = top = bottom = 1

  stones = 3 # 4th added in the loop
  while True:
    stones += 1

    # Finds how many can be filled
    fill = min(left, right) * min(top, bottom)
    if left != right: # by one
      fill += bottom - 1
    elif top != bottom: # by one
      fill += right - 1

    if fill + stones >= K:
      return stones

    # Increment order: left -> right ; bottom -> top
    if left > right:
      right += 1
      continue

    if bottom > top:
      top += 1
      continue

    left_right_finished = N - 2 == left == right
    top_bottom_finished = M - 2 == top == bottom

    if left_right_finished and top_bottom_finished:
      return K - fill

    if left == top and not left_right_finished:
      left += 1
    elif top_bottom_finished:
      left += 1
    else:
      bottom += 1

# I/O processing
fname = sys.argv[1]
with open(fname, "r") as fin:
  with open("output.txt", "w") as fout:
    T = int(fin.readline())
    for case in range(1, T + 1):
      inputs = map(int, fin.readline().split())
      result = enclosure(*inputs)
      fout.write("Case #{case}: {result}\n".format(**locals()))
