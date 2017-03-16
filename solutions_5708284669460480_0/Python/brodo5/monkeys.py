import math
import itertools
import sys

FILENAME = 'B-small-attempt2'

f = open(FILENAME + '.in', 'r')
tests = int(f.readline())
sys.stdout = open(FILENAME + '.out', 'w')
for test in range(tests):
  k, l, s = map(int, f.readline().split())
  keyboard = f.readline().rstrip()
  target = f.readline().rstrip()
  out = 0
  p = 1.0 / len(keyboard) ** s
  best = 0
  for combo in itertools.product(keyboard, repeat = s):
    total = 0
    combo = ''.join(combo)
    for i in range(s - len(target) + 1):
      if combo[i:i + len(target)] == target:
        total += 1
    if total > best:
      best = total
    out += total * p
  print 'Case #%d: %f' % (test + 1, best - out)
