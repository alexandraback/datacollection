#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from sys import stdin
from itertools import combinations

def main():
  ts = int(stdin.readline())
  for idx in range(1, ts+1):
    [c, d, v] = list(map(int, stdin.readline().split(" ")))
    ds = list(map(int, stdin.readline().split(" ")))
    print("Case #%d: %s" % (idx, solve(c, d, v, ds)))

def is_sat(ds, tar, v):
  xs = set([])
  d = len(ds)
  for l in range(1, d+1):
    for subset in combinations(ds, l):
      sm = sum(subset)
      if sm <= v:
        xs.add(sum(subset))
  return tar - xs == set([])

def solve(c, d, v, ds):
  tar = set(range(1, v+1))
  if is_sat(ds, tar, v):
    return 0
  candidates = tar - set(ds)
  
  for l in range(1, len(candidates)+1):
    for added in combinations(candidates, l):
      nds = ds + list(added)
      if is_sat(nds, tar, v):
        return l

if __name__=="__main__":
   main()
