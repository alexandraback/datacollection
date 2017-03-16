nc = input()
for ci in range(1, nc+1):
  C, F, X = map(float, raw_input().split())
  k = 0
  g = 0
  a = 2.0
  u, v = 0.0, 0.0
  res = X / 2
  while True:
    t = g + X / a 
    res = min(res, t)
    g += C / a
    a += F
    k += 1
    if k >= 2 and t > v:
      break
    u, v = v, t
  print 'Case #%d: %.7f' % (ci, res)
