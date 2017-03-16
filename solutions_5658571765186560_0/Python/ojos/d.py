#!/usr/bin/env python

for nnn in xrange(1, int(raw_input())+1):
  print "Case #%d:" % (nnn),
  X, R, C = [int(x) for x in raw_input().split()]
  R, C = sorted([R,C])
  if X == 1:
    print "GABRIEL"
  elif X == 2:
    print "GABRIEL" if R % 2 == 0 or C % 2 == 0 else "RICHARD"
  elif X == 3:
    if R == 2 and C == 3 or R == 3 and (C == 3 or C == 4):
      print "GABRIEL"
    else:
      print "RICHARD"
  elif X == 4:
    print "GABRIEL" if R == 3 and C == 4 or R == 4 else "RICHARD"

