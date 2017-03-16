#!/usr/bin/python3
import sys

T = int(sys.stdin.readline().strip())
for t in range(T):
  N = int(sys.stdin.readline().strip())
  n = 0
  seen = {}
  counted = 0
  if N != 0:
    while True:
      n += N
      for c in list(str(n)):
        seen[c] = 1
      if len(seen) == 10:
        break
  print 'Case #%d: %s' % (t + 1, 'INSOMNIA' if n == 0 else '%d' % (n))
