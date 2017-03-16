#!/usr/bin/env python

import string
import sys

mapping = {}

def handle(lst):
  N = lst[0]
  S = lst[1]
  p = lst[2]
  tps = lst[3:]
  tps.sort()

  sure = 0
  maybe = 0

  for x in tps:
    if x % 3 == 0:
      if x / 3 >= p:
        sure += 1
      elif x > 0 and x / 3 + 1 >= p:
        maybe += 1
    elif x % 3 == 1:
      if x / 3 + 1 >= p:
        sure += 1
    else:
      if x / 3 + 1 >= p:
        sure += 1
      elif x / 3 + 2 >= p:
        maybe += 1

  return sure + min(maybe, S)

def main():
  i = sys.stdin.readlines()
  for case in range(1, int(i[0]) + 1):
    print "Case #" + str(case) + ": " + \
      str(handle(map(int, i[case].strip().split(' '))))



main()
