#!/usr/bin/python

from sys import stdin as I

def solve():
  X, R, C = map(int, I.readline().split())

  if (R * C) % X != 0:
    return False

  if R < X and C < X:
    return False

  if X >= 7:
    return False

  if R*2 < X or C*2 < X:
    return False

  if X <= 3:
    return True

  return R*2-1 > X and C*2-1 > X

T = int(I.readline())
for i in range(T):
    print("Case #%i: %s" % (i+1, solve() and "GABRIEL" or "RICHARD"))
