#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from sys import stdin

def main():
  ts = int(stdin.readline())
  for i in range(1, ts+1):
    s = stdin.readline().strip()
    sol = solve(s)
    print("Case #%d: %s" % (i, sol))

def solve(s):
  n = len(s)
  if s == n * "+":
    return 0
  prev = s[0]
  flips = 0 if prev == '+' else 1
  for curr in s[1:]:
    if curr == '-' and prev == '+':
      flips += 2
    prev = curr
  return flips


if __name__=="__main__":
   main()
