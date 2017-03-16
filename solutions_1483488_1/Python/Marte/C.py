import sys
import string
import bisect
inp = sys.stdin
T = int(inp.readline())

MAX = 2000000

rots = {}
for i in xrange(1, MAX+1):
  s = str(i)
  length = len(s)
  s2 = s + s
  r = set(int(s2[i:i+length]) for i in xrange(1, length))
  rots[i] = sorted(a for a in r if i < a <= MAX)


for cas in xrange(1, T + 1):
  print "Case #%d:" % cas,
  a, b = map(int, inp.readline().strip().split(' '))
  c = 0
  for x in xrange(a, b+1):
    c += bisect.bisect_right(rots[x], b)
  print c

