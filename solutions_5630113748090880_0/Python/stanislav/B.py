import sys

def run(t):
  N = int(raw_input())
  counts = {}
  for i in range(2 * N - 1):
    for r in map(int, raw_input().split()):
      if not r in counts:
        counts[r] = 1
      else:
        counts[r] += 1
  result = []
  for k, v in counts.iteritems():
    if v % 2 == 1:
      result.append(k)

  print('Case #{}: {}'.format(t, ' '.join(map(str, sorted(result)))))

T = int(raw_input())
for t in xrange(1, T + 1):
  run(t)
