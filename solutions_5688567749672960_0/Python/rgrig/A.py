#!/usr/bin/env python3

from collections import deque

import sys

def prev(x):
  assert x > 1
  ys = [x - 1]
  xs = str(x)
  if xs[-1] != '0':
    y = int(xs[::-1])
    ys.append(y)
  return ys

def solve(x):
  nxt, now = [x], []
  seen = set(nxt)
  d = 1
  while True:
    nxt, now = [], nxt
    for x in now:
      if x == 1:
        return d
      for y in prev(x):
        if y in seen:
          continue
        seen.add(y)
        nxt.append(y)
    d += 1
    sys.stderr.write('D={}\n'.format(d))

xs = sys.stdin.readlines()
for t in range(1,len(xs)):
  y = solve(int(xs[t]))
  sys.stdout.write('Case #{}: {}\n'.format(t, y))
