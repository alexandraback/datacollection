#!/usr/bin/python

from sys import stdin as I

def solve(n):
  c, p = I.readline().split()
  c = int(c)+1
  p = map(int, p)
  p.append(0)
  s = 0
  sol = 0

  for i in range(c):
    if s < i:
      sol += i-s
      s += i-s
    s += p[i]

  print("Case #%i: %i" % (n+1, sol))

T = int(I.readline())
for i in range(T):
    solve(i)
