def findgain(EE, E, R, N, v):
  if N == 1: return E*v[0]
  gain = 0
  for e in xrange(E+1):
    ee = E-e+R
    if ee > EE: ee = EE
    g = findgain(EE, ee, R, N-1, v[1:])
    g += e*v[0]
    if g > gain: gain = g
  return gain


NNN = int(raw_input())
for nnn in xrange(1, NNN+1):
  print "Case #%d:" % (nnn),
  E, R, N = [int(x) for x in raw_input().split()]
  v = [int(x) for x in raw_input().split()]
  gain = 0
  if E == R:
    gain = sum([E*x for x in v])
  else:
    gain = findgain(E, E, R, N, v)

  print gain
