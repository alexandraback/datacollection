#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from sys import stdin

def main():
  ts = int(stdin.readline())
  for idx in range(1, ts+1):
    [r, c, w] = list(map(int, stdin.readline().split(" ")))
    print("Case #%d: %s" % (idx, solve(r, c, w)))

def solve(r, c, w):
  if c % w == 0:
    return w + (c // w - 1)
  else:
    return c // w + w

if __name__=="__main__":
   main()
