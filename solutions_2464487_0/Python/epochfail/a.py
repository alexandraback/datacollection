from math import *

def solve():
  r, paint = map(int, raw_input().split())

  lo, hi = 1, 10**18 * 3

  while lo < hi:
    C = (lo + hi) / 2
    delta = 2*C*C + 2*C*(r+1) + 2*r + C - paint

    if delta < 0:
      lo = C + 1
    else:
      hi = C

  print lo

n = int(raw_input())
for T in xrange(n):
  print('Case #%d:' % (T+1)),
  solve()
