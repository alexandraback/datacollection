#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

def solve(t, i):
  smax, s = t.split(' ')
  res = 0
  nb_stand = 0
  for k in xrange(0, len(s)):
    if nb_stand < k:
      tmp = k - nb_stand
      res += tmp
      nb_stand += tmp
    nb_stand += int(s[k])
  print 'case #%d: %d'%(i+1, res)

if __name__ == "__main__":
  with open(sys.argv[1]) as f:
    buf = f.read()
  t = buf.split("\n")
  nb_tests = int(t[0])
  t = t[1:]
  for k in xrange(0, nb_tests):
    solve(t[k], k)
