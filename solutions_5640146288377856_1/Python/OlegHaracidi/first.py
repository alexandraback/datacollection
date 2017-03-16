T = int(raw_input())
for i in xrange(T):
  r, c, w = tuple(map(int, raw_input().split()))
  k = r * (c // w) + w - 1 + (c % w > 0)
  print "Case #{}: {}".format(i + 1, k)
