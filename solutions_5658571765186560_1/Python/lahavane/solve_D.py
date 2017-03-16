#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

def solve(X, R, C, i):
  if X == 1:
    print 'Case #%d: GABRIEL'%i
    return

  if X > 6:
    print 'Case #%d: RICHARD'%i
    return

  if (R*C) % X != 0:
    print 'Case #%d: RICHARD'%i
    return

  if X > R and X > C:
    print 'Case #%d: RICHARD'%i
    return

  if R == 1 or C == 1:
    if X > 2:
      print 'Case #%d: RICHARD'%i
      return
    if C % 2 != 0 and R % 2 != 0:
      print 'Case #%d: RICHARD'%i
      return
    print 'Case #%d: GABRIEL'%i
    return

  if R == 2 or C == 2:
    if X > 4:
      print 'Case #%d: RICHARD'%i
      return

  if R == 2 and C == 2:
    if X > 2:
      print 'Case #%d: RICHARD'%i
      return
    else:
      print 'Case #%d: GABRIEL'%i
      return

  if (R == 2 and C == 4) or (R == 4 and C == 2):
    if X > 2:
      print 'Case #%d: RICHARD'%i
      return
    else:
      print 'Case #%d: GABRIEL'%i
      return

  if X == 5 and R == 3:
    if C not in [10, 15, 20]:
      print 'Case #%d: RICHARD'%i
      return

  if X == 5 and C == 3:
    if R not in [10, 15, 20]:
      print 'Case #%d: RICHARD'%i
      return

  if X == 6 and (R == 3 or C == 3):
    print 'Case #%d: RICHARD'%i
    return
  
  print 'Case #%d: GABRIEL'%i

if __name__ == "__main__":
  with open(sys.argv[1]) as f:
    buf = f.read()
  t = buf.split("\n")
  nb_tests = int(t[0])
  t = t[1:]
  for k in xrange(0, nb_tests):
    X, R, C = map(int, t[k].split(' '))
    solve(X, R, C, k+1)
