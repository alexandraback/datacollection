#!/usr/bin/python

import sys

def case(N):
  if not N:
    return 'INSOMNIA'
  seen = []
  i = 0
  v = 0
  while len(seen) < 10:
    #print v, seen
    i += 1
    v += N
    n = v
    while n > 0:
      (n,d) = divmod(n,10)
      if d not in seen:
        seen.append(d)
  return '%d'%v
     



f = open(sys.argv[1])
T = int(f.readline())
for i in xrange(T):
  line = f.readline().strip()
  N = int(line)
  print "Case #%d: %s"%(i+1, case(N))

