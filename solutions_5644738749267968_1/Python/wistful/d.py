for tc in xrange(int(raw_input())):
  n = int(raw_input())
  a = sorted(map(float, raw_input().split()))
  b = sorted(map(float, raw_input().split()))

  w = n
  j = 0
  for i in xrange(n):
    while j < n and b[j] < a[i]: j += 1
    if j < n:
      w -= 1
      j += 1

  v = 0
  j = 0
  for i in xrange(n):
    if b[j] < a[i]:
      v += 1
      j += 1

  print "Case #{}: {} {}".format(tc + 1, v, w)