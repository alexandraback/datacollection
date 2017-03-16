import sys
import itertools
sys.setrecursionlimit(10000)

def inv(x): return '-' if x == '+' else '+'

tc = int(sys.stdin.readline().strip())

for tmp_tc in xrange(tc):
  xs = list(sys.stdin.readline().strip())
  res = 0
  while True:
    last_minus, first_minus = None, None
    for i, x in enumerate(xs):
      if x == '-': last_minus = i
      if x == '-' and first_minus is None: first_minus = i
    if last_minus is None: break
    if first_minus:
      for i in xrange(first_minus):
        xs[i] = '-'
      res += 1
    for i in xrange(last_minus/2+1):
      tmp_a, tmp_b = inv(xs[last_minus-i]), inv(xs[i])
      xs[i], xs[last_minus-i] = tmp_a, tmp_b
    res += 1
  print "Case #%d: %d" % (1+tmp_tc, res)

