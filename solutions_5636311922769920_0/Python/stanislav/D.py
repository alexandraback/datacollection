import sys

def run(t):
  K, C, S = map(int, raw_input().split())
  print('Case #{}: {}'.format(t, " ".join([str(i) for i in range(1, S + 1)])))

T = int(raw_input())
for t in xrange(1, T + 1):
  run(t)
