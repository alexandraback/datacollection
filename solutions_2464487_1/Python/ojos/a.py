import math

NNN = int(raw_input())
for nnn in xrange(1, NNN+1):
  print "Case #%d:" % (nnn),
  r, t = [int(x) for x in raw_input().split()]
  n =  (1 - 2*r + math.sqrt(4*r*r - 4*r + 1 + 8*t)) / 4
  print int(n)
