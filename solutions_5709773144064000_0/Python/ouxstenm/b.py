NNN = int(raw_input())
for nnn in xrange(1, NNN+1):
  C, F, X = [float(x) for x in raw_input().split()]
  r = 2.0
  t = 0.0
  XC = X-C

  while F*XC > r*C:
    t += float(C)/r
    r += F

  print "Case #%d: %0.7f" % (nnn, t + X/r)
