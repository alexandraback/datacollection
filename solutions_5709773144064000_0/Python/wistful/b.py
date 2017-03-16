for tc in xrange(1, int(raw_input()) + 1):
  c, f, x = map(float, raw_input().split())
  v = 0
  t = 0
  k = 2;
  best = 1e23
  while v <= x:
    r = t + (x - v) / k
    if r < best:
      best = r
    else:
      break
    if v < c:
      t += (c - v) / k
      v = c
    v -= c
    k += f
  print "Case #{}: {}".format(tc, best)