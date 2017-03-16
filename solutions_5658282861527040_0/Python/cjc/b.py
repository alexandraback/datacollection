import itertools

from collections import defaultdict
from random import randint



def solve(tcase):
  a, b, k = (int(e) for e in raw_input('').split())

  res = 0
  for i in xrange(a):
    for j in xrange(b):
      c = i & j
      if c < k: res += 1

  print 'Case #%d: %s' % (tcase, res)

T = int(raw_input(''))
for tcase in xrange(1, T + 1):
  solve(tcase)