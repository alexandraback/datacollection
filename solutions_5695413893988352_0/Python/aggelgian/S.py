#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from sys import stdin
from  collections import defaultdict
from itertools import permutations

def main():
  ts = int(stdin.readline())
  for i in range(1, ts+1):
    l = stdin.readline().strip().split(" ")
    sol = solve(l)
    print("Case #%d: %s" % (i, sol))

def m(s):
  xs = [""]
  ds = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
  for i in range(len(s)):
    if s[i] != '?':
      xs = [x + s[i] for x in xs]
    else:
      tmp = []
      for x in xs:
        for d in ds:
          tmp.append(x + d)
      xs = tmp
  return xs

def solve(l):
  l1, l2 = m(l[0]), m(l[1])
  mdiff = 1000
  sols = []
  for x in l1:
    for y in l2:
      df = abs(int(x) - int(y))
      if df < mdiff:
        mdiff = df
        sols = [(x, y)]
      elif df == mdiff:
        sols.append((x, y))
  x, y = list(sorted(sols))[0]
  return x + " " + y


if __name__=="__main__":
   main()

