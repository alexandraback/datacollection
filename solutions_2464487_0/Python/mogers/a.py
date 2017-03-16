import sys
import math 

numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):
  R, T = [int(w) for w in sys.stdin.readline().split()]
  b = 2*R - 1
  x = -b + math.sqrt( b*b + 8*T )
  res = int(x / 4)
  am = 2*R*res + res*(-2+4*res)/2
  if (am > T):
    res = res - 1
  print 'Case #%d: %d' % (casenum, res)
