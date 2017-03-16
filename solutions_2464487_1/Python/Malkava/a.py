T = int(input())

def f(n, r):
  return n*(2*(n+1) + 2*r - 3)

for cas in xrange(1,T+1):
  inp = map(int, raw_input().split())
  t = inp[1]
  r = inp[0]

  left = 1
  right = t

  while(right - left > 1):
    mid = (right + left)/2
    if f(mid, r) > t:
      right = mid
    else:
      left = mid
  print "Case #%d: %d" % (cas, left)


