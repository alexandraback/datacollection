#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from sys import stdin, stdout, setrecursionlimit
from operator import itemgetter
setrecursionlimit(99999999)

def main():
  ts = int(stdin.readline())
  rvs = [None] * 1000010
  for i in range(1, 1000000):
    rvs[i] = int(str(i)[::-1])
  for idx in range(1, ts+1):
    n = int(stdin.readline())
    xs = {}
    for i in range(1, 10):
      xs[i] = i
    solve(9, n, xs, rvs)
    x = xs[n]
    print("Case #%d: %s" % (idx, x))

def solve(i, target, cnt, rvs):
  for i in range(i, target+1):
    if i > target:
      return
    curr = cnt[i] + 1
    
    ni = i + 1
    if ni in cnt:
      cnt[ni] = min(cnt[ni], curr)
    else:
      cnt[ni] = curr
    
    ri = rvs[i]
    if ri in cnt:
      cnt[ri] = min(cnt[ri], curr)
    else:
      cnt[ri] = curr


if __name__=="__main__":
   main()
