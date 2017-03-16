from sys import stdin
import re

Q = int(stdin.readline())
for qq in xrange(Q):
  A,B,K = map(int,stdin.readline().split())
  res = 0
  for x in xrange(A):
    for y in xrange(B):
      res += (x & y) < K
  print "Case #"+str(qq+1)+": "+str(res)