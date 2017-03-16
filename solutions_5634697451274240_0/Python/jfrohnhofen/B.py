#!/usr/bin/python

from sys import stdin as I

def solve(n):
  s = I.readline()[-1::-1][1:]
  c = '+'
  r = 0

  for x in s:
    if x != c:
      r += 1
      c = x

  print("Case #%i: %i" % (n + 1, r))

T = int(I.readline())
for i in range(T):
    solve(i)
