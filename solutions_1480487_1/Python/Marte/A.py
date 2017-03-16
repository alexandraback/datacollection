import sys
import string
inp = sys.stdin
T = int(inp.readline())

for cas in xrange(1, T + 1):
  print "Case #%d:" % cas,
  ints = [float(x) for x in inp.readline().split(' ')]
  N = ints.pop(0)
  assert N == len(ints)
  tot = sum(ints)
  num = N
  target = tot * 2.0 / N
  diff = 0
  for x in ints:
    if x > target:
      diff += x-target
      num -= 1
  target -= diff / num
  percent = 0
  for x in ints:
    d = max(0.0, (target - x) / tot)
    print d*100,
    percent += d
  print
  assert abs(percent - 1) < 1e-4
