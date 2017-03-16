import sys

def run(t):
  N = int(raw_input())
  if N == 0:
    print('Case #{}: {}'.format(t, 'INSOMNIA'))
    return
  digits = set()
  n = N
  while True:
    digits |= set(str(n))
    if len(digits) == 10:
      print('Case #{}: {}'.format(t, n))
      return
    n += N

T = int(raw_input())
for t in xrange(1, T + 1):
  run(t)
