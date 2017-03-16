#!/usr/bin/python2

from sys import stdin

def solve(g):
  for s in g.keys():
    q = [s]
    f = set()

    while q:
      n = q[0]
      q = q[1:]

      if n in f:
        return True
      else:
        f.add(n)
        q.extend(g[n])


  return False

n = int(stdin.readline())
for i in xrange(1, n+1):
  g = {}
  nd = int(stdin.readline())

  for j in xrange(nd):
    g[j] = [int(x)-1 for x in stdin.readline().strip().split()[1:]]

  res = solve(g)

  print 'Case #%d: %s' % (i, ["No", "Yes"][res])
