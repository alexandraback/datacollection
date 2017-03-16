#!/usr/bin/env python


def can(x,r,c):
  if r*c%x != 0: return False
  if x < 3: return True
  if c>r:
    r,c=c,r
  if x == 3:
    if (r,c) == (3,1):
      return False
    return True
  if x == 4:
    if r < 4: return False
    if r == 4 and c < 3: return False
    return True
  raise Exception

T = int(raw_input())
for t in xrange(T):
  x,r,c = map(int,raw_input().split())
  print "Case #%d:" % (t+1), "GABRIEL" if can(x,r,c) else "RICHARD"
