#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

def solve(nb, t, i):
  m = max(t)
  res = [m]
  nb_special = 0
  nb_no_split = 0
  while(m > 3):
    # split diner
    t.remove(m)
    if len(t) > 0:
      m2 = max(t)
    else:
      m2 = 0
    if m > 8 and m2 in [0, 1, 2, 3, 4, 6]:
      t.append(m-3)
      t.append(3)
    else:
      t.append((m+1)/2)
      t.append(m/2)
    m = max(t)
    nb_special += 1
    res.append(m+nb_special)
  print 'Case #%d: %d'%(i, min(res))

if __name__ == "__main__":
  with open(sys.argv[1]) as f:
    buf = f.read()
  t = buf.split("\n")
  nb_tests = int(t[0])
  t = t[1:]
  for k in xrange(0, nb_tests):
    solve(t[k*2], map(int, t[k*2+1].split(' ')), k+1)
