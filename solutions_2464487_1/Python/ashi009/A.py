T=input()
for i in range(1,T+1):
  r,t = map(int, raw_input().split())
  L = 0
  R = 1e18
  res = -1
  while L <= R:
    n = (L + R) // 2
    nt = (n+1)*(2*r+2*n+1)
    if nt > t:
      R = n-1
    else:
      res = n
      L = n+1
  print "Case #%d: %d" % (i, res+1)