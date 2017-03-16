#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

def solve(t, i):
  K, C, S = map(int, t.split(' '))
  res = ''
  for k in xrange(1, S+1):
    res += ' ' + str(k)
  print 'Case #%d:%s'%(i, res)

if __name__ == "__main__":
  with open(sys.argv[1]) as f:
    buf = f.read()
  t = buf.split("\n")
  nb_tests = int(t[0])
  t = t[1:]
  for k in xrange(0, nb_tests):
    solve(t[k], k+1)
