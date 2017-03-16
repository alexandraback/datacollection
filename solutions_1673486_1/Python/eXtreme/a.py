import sys

T = int(sys.stdin.readline())

for t in range(1, T+1):
  A, B = map(int, sys.stdin.readline().strip().split())
  p = map(float, sys.stdin.readline().strip().split())

  q = [1.] + p
  for i in range(1, len(q)):
    q[i] *= q[i - 1]

  # enter
  if A == B:
    bestExp = q[B] * 1 + (1. - q[B]) * (B + 2)
  else:
    bestExp = B + 2

  # BS
  for backs in range(A + 1):
    expect = q[A - backs] * (B - A + 2 * backs + 1) + (1. - q[A - backs]) * (2 * B - A + 2 * backs + 2)
    #print 'backs, expect', backs, expect
    bestExp = min(bestExp, expect)

  print 'Case #%d: %f' % (t, bestExp)
