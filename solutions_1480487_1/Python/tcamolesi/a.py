#!/usr/bin/python2

from sys import stdin

def solve(js):
  ejs = sorted(enumerate(js), key=lambda x: x[1])
  solved = []

  li = ejs[0][1]
  total = 0.
  S = sum(js)
  for i, ji in ejs:
    delta = (ji - li)/S
    c = delta*(len(solved))

    if total + c > 1.:
      c = 1. - total
      delta = c/(len(solved))

    for s in solved:
      s[1] += delta

    solved.append([i, 0.])
    li = ji
    total += c

  if total < 1.0:
    delta = (1.-total)/len(js)
    for s in solved:
      s[1] += delta

  sols = [0.] * len(js)

  for i, ji in solved:
    sols[i] = ji*100

  return sols


n = int(stdin.readline())
for i in xrange(1, n+1):
  js = [float(j) for j in stdin.readline().strip().split()[1:]]
  res = solve(js)

  print 'Case #%d: %s' % (i, ' '.join(map(str, res)))
