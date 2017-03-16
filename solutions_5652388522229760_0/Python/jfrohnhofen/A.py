#!/usr/bin/python

from sys import stdin as I

def solve(n):
  N = int(I.readline())
  
  if N == 0:
    print("Case #%i: INSOMNIA" % (n+1))
    return

  M = 0
  seen = set()
  while len(seen) < 10:
    M += N
    for ch in str(M):
      seen.add(ch)
  
  print("Case #%i: %i" % (n+1, M))

T = int(I.readline())
for i in range(T):
    solve(i)
