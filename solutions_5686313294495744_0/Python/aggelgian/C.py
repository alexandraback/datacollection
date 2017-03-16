#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from sys import stdin
from  collections import defaultdict

def main():
  ts = int(stdin.readline())
  for i in range(1, ts+1):
    n = int(stdin.readline().strip())
    ls = [stdin.readline().strip().split(" ") for _ in range(n)]
    sol = solve(n, ls)
    print("Case #%d: %s" % (i, sol))

def solve(n, ls):
  d1, d2 = defaultdict(int), defaultdict(int)
  d1F, d2F = defaultdict(lambda: False), defaultdict(lambda: False)
  n = 0
  for l in ls:
    d1[l[0]] += 1
    d2[l[1]] += 1
  for l in ls:
    l1, l2 = l[0], l[1]
    if d1[l1] > 1 and d2[l2] > 1 and d1F[l1] and d2F[l2]:
      n += 1
    d1F[l1] = True
    d2F[l2] = True
  return n


if __name__=="__main__":
   main()

