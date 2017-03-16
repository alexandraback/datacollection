#!/usr/bin/python

import sys

T = int(sys.stdin.readline())
for test in range(0, T):
  tmp = sys.stdin.readline().rstrip('\n').split(' ')
  A = int(tmp[0])
  B = int(tmp[1])

  r = {}
  for n in range(A, B):
    nstr = str(n)
    for i in range(0, len(nstr)):
      mstr = nstr[i:] + nstr[:i]
      m = int(mstr)
      if A <= n and n < m and m <= B:
        #if (n,m) in r:
        #  print "duplicate! A(%d) <= n(%d) < m(%d) <= B(%d)" % (A, n, m, B)
        r[(n,m)] = 1
        #print "A(%d) <= n(%d) < m(%d) <= B(%d)" % (A, n, m, B)
  print "Case #%d: %d" % (test+1, len(r))
