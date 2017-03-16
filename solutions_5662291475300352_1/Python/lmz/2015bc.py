import sys

tc = int(sys.stdin.readline())
for tmp_tc in xrange(tc):
  [ N ] = map(lambda x: int(x), sys.stdin.readline().split(' '))
  hikers = []
  for _n in xrange(N):
    [ D, H, M ] = map(lambda x: int(x), sys.stdin.readline().split(' '))
    for h in xrange(H):
      hikers.append((D, M+h))
  res = 0
  if len(hikers) >= 2:
    hikers = map(lambda (d, m): (m*(360-d), d, m), hikers)
    hikers.sort()
    res = len(hikers)
    for i, (t1, d1, m1) in enumerate(hikers):
      ok = True
      for j in xrange(i):
        (t2, d2, m2) = hikers[j]
      #  if m1 * d1 + t2 >= 720 * m1: ok = False
        if m2 * d2 + t1 >= 720 * m2: ok =False
        else: ok = True
      if ok: res -= 1
  print "Case #%d: %d" % (tmp_tc + 1, res)
