#!/usr/bin/python

from sys import stdin as I

def solve():
  D = int(I.readline())
  Di = map(int, I.readline().split())

  Di.sort()
  sol = Di[-1]

  for threshold in range(sol, 1, -1):
    special = 0
    for d in Di:
      special += (d-1) / threshold
      if special + threshold >= sol: break

    sol = min(sol, special + threshold)

  return sol

T = int(I.readline())
for i in range(T):
  print("Case #%i: %i" % (i+1, solve()))
