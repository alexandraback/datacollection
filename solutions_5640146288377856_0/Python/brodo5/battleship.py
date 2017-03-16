import math
import itertools
import sys

FILENAME = 'A-small-attempt2'

f = open(FILENAME + '.in', 'r')
tests = int(f.readline())
sys.stdout = open(FILENAME + '.out', 'w')
for test in range(tests):
  r, c, w = map(int, f.readline().split())
  if w == 1:
    out = r * c
  else:
    out = 0
    out += (r - 1) * (c / w)
    out += (c / w) - 1
    out += w
    if c % w != 0:
      out += 1
  print 'Case #%d: %d' % (test + 1, out)
