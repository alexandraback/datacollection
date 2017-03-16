#!/usr/bin/env python

# print "%.7f" % 83.33333333333333


import sys

def solve(C, F, X):
  res = 0.
  inc = 2.

  while True:
    buy_farm = C/inc
    buy_farm_wait = buy_farm + X/(inc + F)
    just_wait = X/inc

    if buy_farm_wait < just_wait:
      res += buy_farm
      inc += F
    else:
      res += just_wait
      break

  return res

f = open(sys.argv[1], 'r')
T = int(f.readline())

for t in range(T):
  C, F, X = f.readline().strip().split()

  print "Case #%d: %.7f" % ((t+1), solve(float(C), float(F), float(X)))
