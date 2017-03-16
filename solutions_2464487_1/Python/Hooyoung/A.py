#!/usr/bin/env python
import math

def ri():
  x=''
  while not x:
    x=raw_input().strip()
  return x

"""
  \sum_{i=0}^{n-1} 4i+2r+1

  2n^2 - n + 2rn
  2n^2 + (2r-1)n <= t

  (2r-1)^2 + 4*2*t
"""

T = int(ri())
for i in xrange(T):
  r,t = map(int,ri().split())
  d = r*r-r+.25+2*t
  if d<0:
    n = 0
  else:
    n = int(math.floor(.5 * (.5-r + d**.5)))
    while 2*n*n+(2*r-1)*n>t:
      n -= 1
    while 2*n*n+(2*r-1)*n<=t:
      n += 1
    while 2*n*n+(2*r-1)*n>t:
      n -= 1
    # yay!
  print 'Case #%d:'%(i+1), n
