from __future__ import division
import math
import numpy as np
import bisect
from operator import sub

fname = "D-small-attempt0.in.txt"
# fname = "test.in"

def solve(N,K):
  K2 = list(K)
  # print N
  # print K

  # probably better way of doing this

  for n in N:
    pos = bisect.bisect(K2, n)
    # print pos
    if pos == len(K2):
      break
    del K2[pos]
  res1 = len(K2)

  K2 = list(K)
  N2 = list(N)

  for i in range(len(K2))[::-1]:
    k = K2[i]
    # pos = bisect.bisect(N2, k) - 1
    # print k, N2[0]
    
    diff = map(sub, N2, K2)
    # print N2
    # print K2
    # print diff
    if all([x >= 0 for x in diff]):
      break
    if k < N2[0]:
      break
    # print N2, k, pos
    del N2[0]
    del K2[i]
  res2 = len(N2)

  return " ".join(map(str,[res2,res1]))

def main():
  with open(fname) as f:
    for i in xrange(int(f.readline())):
      _ = f.readline()
      N = sorted(map(float, f.readline().split()))
      K = sorted(map(float, f.readline().split()))
      print 'Case #%s: %s' % (i + 1, solve(N,K))
  
main()