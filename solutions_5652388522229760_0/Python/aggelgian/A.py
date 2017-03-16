#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from sys import stdin

def main():
  ts = int(stdin.readline())
  for i in range(1, ts+1):
    n = int(stdin.readline())
    sol = solve(n)
    print("Case #%d: %s" % (i, sol))

def solve(n):
  if n == 0:
    return "INSOMNIA"
  curr = 0
  seen = set()
  while len(seen) < 10:
    curr += n
    [seen.add(d) for d in str(curr)]
  return curr

if __name__=="__main__":
   main()

