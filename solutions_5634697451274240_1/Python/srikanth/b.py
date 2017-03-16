#!/usr/bin/python

import sys
from itertools import groupby

ipfile, opfile = sys.stdin, sys.stdout

T = int(ipfile.readline().strip())
for t in xrange(1,T+1):
  ipstr = ipfile.readline().strip()
  moves = 0
  newipstr = "".join([k for k,g in groupby(ipstr)])
  while len(newipstr)>0:
    if newipstr.endswith('+'):
      newipstr = newipstr[:-1]
      continue
    if newipstr.startswith('-'):
      moves += 1
      newipstr = newipstr[1:]
      continue
    if newipstr.startswith('+-'):
      moves += 2
      newipstr = newipstr[2:]
      continue
  opfile.write('Case #%d: %d\n' % (t, moves))
