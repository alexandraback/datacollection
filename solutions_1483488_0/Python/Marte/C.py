import sys
import string
inp = sys.stdin
T = int(inp.readline())

def is_recycled(n, m):
  n = str(n)
  m = str(m)
  return m in (n + n)

for cas in xrange(1, T + 1):
  print "Case #%d:" % cas,
  a, b = map(int, inp.readline().strip().split(' '))
  c = 0
  for x in xrange(a, b):
    for y in xrange(x+1, b+1):
      c += is_recycled(x, y)
  print c

