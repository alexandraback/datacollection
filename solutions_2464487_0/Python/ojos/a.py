NNN = int(raw_input())
for nnn in xrange(1, NNN+1):
  print "Case #%d:" % (nnn),
  r, t = [int(x) for x in raw_input().split()]
  r1 = r
  r2 = r+1
  s = 0
  n = 0
  while s <= t:
    s += r2*r2 - r1*r1
    r1 += 2
    r2 += 2
    n += 1
  print n - 1
