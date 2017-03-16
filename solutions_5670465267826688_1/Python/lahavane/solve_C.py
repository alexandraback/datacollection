#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

def red(s, sign):
  mul = {
    'ii': ('', -sign),
    'ij': ('k', sign),
    'ik': ('j', -sign),
    'ji': ('k', -sign),
    'jj': ('', -sign),
    'jk': ('i', sign),
    'ki': ('j', sign),
    'kj': ('i', -sign),
    'kk': ('', -sign)
  }
  return mul[s]

def solve(L, X, t, i):
  if len(set(t)) == 1:
    print 'Case #%d: NO'%i
    return

  sign = 1

  if X < 5:
    s = t*X
  else: # X >= 5
    rs = t
    while len(rs) > 1:
      tmp, sign = red(rs[0:2], sign)
      rs = tmp + rs[2:]
    if (X % 2 == 0):
      rs = ''
    if sign < 0 and (X % 2 == 1):
      sign = -1
    else:
      sign = 1
    while len(rs) > 1:
      tmp, sign = red(rs[0:2], sign)
      rs = tmp + rs[2:]
    s = t + t + rs + t + t

  while s[0] != 'i' and len(s) > 3:
    tmp, sign = red(s[0:2], sign)
    s = tmp + s[2:]
  if s[0] != 'i':
    print 'Case #%d: NO'%i
    return

  s = s[1:]
  while s[0] != 'j' and len(s) > 2:
    tmp, sign = red(s[0:2], sign)
    s = tmp + s[2:]
  if s[0] != 'j':
    print 'Case #%d: NO'%i
    return

  s = s[1:]
  while len(s) > 1:
    tmp, sign = red(s[0:2], sign)
    s = tmp + s[2:]
  if len(s) == 0 or s[0] != 'k' or sign < 0:
    print 'Case #%d: NO'%i
    return
  
  print 'Case #%d: YES'%i
  return


if __name__ == "__main__":
  with open(sys.argv[1]) as f:
    buf = f.read()
  t = buf.split("\n")
  nb_tests = int(t[0])
  t = t[1:]
  for k in xrange(0, nb_tests):
    L, X = map( int, t[k*2].split(' '))
    solve(L, X, t[k*2+1], k+1)
