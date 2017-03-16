#!/usr/bin/python2

from sys import stdin

def solve(n, s, points):
  tab = [(True, False)] * 31
  for x in xrange(0, 11):
    for y in xrange(x, min(x+2, 10)+1):
      for z in xrange(y, min(y+2,10)+1):
        if z - x > 2:
          continue

        ms, cs = tab[x+y+z]
        ss = (z - x == 2)
        sol = z >= n
        if not sol:
          continue
        tab[x+y+z] = (ms and (sol and ss)), (cs or sol)

  cs = 0
  ms = 0
  
  for p in points:
    if tab[p][0] and tab[p][1]:
      ms += 1
    if tab[p][1]:
      cs += 1

  return cs - max(0, ms - s)

n = int(stdin.readline())
for i in xrange(1, n+1):
  inp = [int(x) for x in stdin.readline().strip().split()]
  s = inp[1]
  p = inp[2]
  points = inp[3:]

  sol = solve(p, s, points)
  print 'Case #%d: %d' % (i, sol)
