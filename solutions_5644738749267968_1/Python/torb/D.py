from sys import stdin

TC = int(stdin.readline())

for tc in xrange(1, TC+1):
  N = int(stdin.readline())
  Naomi = sorted([float(x) for x in stdin.readline().split()])
  Ken = sorted([float(x) for x in stdin.readline().split()])

  DW = 0
  W = 0

  i2 = 0
  j2 = N-1
  for i in xrange(N):
    if Naomi[i] < Ken[i2]:
      j2 -= 1
    else:
      DW += 1
      i2 += 1

  i2 = 0
  j2 = N - 1
  for i in xrange(N-1, -1, -1):
    if Naomi[i] < Ken[j2]:
      j2 -= 1
    else:
      i2 += 1
      W += 1

  print "Case #%d: %d %d" % (tc, DW, W)

