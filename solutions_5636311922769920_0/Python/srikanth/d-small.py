#!/usr/bin/python

import sys

ipfile, opfile = sys.stdin, sys.stdout

T = int(ipfile.readline().strip())
for t in xrange(1,T+1):
  K, C, S = map(int, ipfile.readline().strip().split())
  if K == S:    # always true for small set
    opstr = " ".join(map(str, range(1, K+1)))    
    opfile.write('Case #%d: %s\n' % (t,opstr))
