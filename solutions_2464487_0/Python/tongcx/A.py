from sys import stdin

def sqrt(x):
  l = 0
  r = x
  res = 0
  while l <= r:
    m = (l+r)/2
    if m*m <= x:
      l = m+1
      res = m
    else:
      r = m-1
  return res

T = int(stdin.readline())
for _ in xrange(1, T+1):
  r,t = map(int, stdin.readline().split())
  print 'Case #{0}: {1}'.format(_, int((sqrt((2*r-1)**2+8*t) - (2*r-1))/4))
