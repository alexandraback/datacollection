#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from sys import stdin

def main():
  ts = int(stdin.readline())
  for i in range(1, ts+1):
    [k, c, s] = list(map(int, stdin.readline().split()))
    sol = solve(k, c, s)
    print("Case #%d: %s" % (i, sol))

def solve(k, c, s):
  if s < k:
    # FIXME
    return "IMPOSSIBLE"
  sol = []
  for i in range(k):
    pos = (i + 1) + i * k * (c - 1)
    sol.append(str(pos))
  return " ".join(sol)


if __name__=="__main__":
   main()
