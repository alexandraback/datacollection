#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os, sys
import math, random


IN, OUT = None, None


def test_case(i):
  OUT.write('Case #%d: ' % i)
  A, N = map(int, IN.readline().split())
  moles = sorted(map(int, IN.readline().split()))
  result = N
  added = 0
  
  if A != 1:
    for i, m in enumerate(moles):
      while moles[i] >= A:
        A += A - 1
        added += 1
      A += moles[i]
      result = min(result, added + N - i - 1)
  
  OUT.write('%d\n' % result)


def main():
  T = int(IN.readline())
  for i in range(1, T+1):
    test_case(i)


if __name__ == '__main__':
  assert len(sys.argv) == 2
  iname = sys.argv[1]
  oname = '%s.out' % sys.argv[1][:-3]
  IN = open(iname, 'rt')
  OUT = open(oname, 'wt')
  main()
  IN.close()
  OUT.close()
