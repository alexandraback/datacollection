#!/usr/bin/env python

from sys import argv

f = open(argv[1])
f.next()
T = 0
for l in f:
  T += 1
  r, t = map(int, l.strip().split(' '))
  u = 1
  v = t + 1
  while u+1 < v:
    w = (u+v)//2
    if 2*w*w+(2*r-1)*w <= t:
      u = w
    else:
      v = w
  print "Case #%d: %d" % (T, u)

