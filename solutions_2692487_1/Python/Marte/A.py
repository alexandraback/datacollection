import sys
import string
import bisect
inp = sys.stdin

def cnt(A, ms):
  if A == 1:
    return len(ms)
  c = 0
  a = A
  for m in ms:
    while a <= m:
      a += a-1
      c += 1
    a += m
  return c

T = int(inp.readline())
for cas in xrange(1, T + 1):
  print "Case #%d:" % cas,
  A, N = map(int, inp.readline().split())
  motes = map(int, inp.readline().split())
  motes.sort()
  ans = N
  for i in xrange(N):
    ms = motes[:N-i]
    ans = min(ans, i + cnt(A, ms))
  print ans
