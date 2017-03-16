#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from sys import stdin
from itertools import combinations, product
from re import finditer

def main():
  ts = int(stdin.readline())
  for idx in range(1, ts+1):
    [k, l, s] = list(map(int, stdin.readline().split(" ")))
    letters = stdin.readline().strip()
    target = stdin.readline().strip()
    print("Case #%d: %.7lf" % (idx, solve(k, l, s, letters, target)))

def cost(search, target):
  n = 0
  t = len(target)
  while len(search) >= t:
    if search[:t] == target:
      n += 1
    search = search[1:]
  return n

def solve(k, l, s, letters, target):
  if set(list(target)) - set(list(letters)) != set([]):
    return 0.0

  ws = ["".join(list(x)) for x in product(letters, repeat=s)]
  ys = [cost(s, target) for s in ws]
  return max(ys) - sum(ys)/len(ys)
  return k

if __name__=="__main__":
   main()
