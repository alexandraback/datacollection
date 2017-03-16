import sys
from fractions import gcd

def run(t):
  P, Q = map(int, raw_input().split('/'))
  d = gcd(P, Q)
  P /= d
  Q /= d
  for i in range (0, 41):
    if Q < 2 ** i:
      print('Case #{}: {}'.format(t, 'impossible'))
      return
    if Q == 2 ** i:
      break
  for i in range (0, 41):
    if (2 ** i) * P >= Q:
      print('Case #{}: {}'.format(t, i))
      return
  print('Case #{}: {}'.format(t, 'impossible'))

T = int(raw_input())
for t in xrange(1, T + 1):
  run(t)
