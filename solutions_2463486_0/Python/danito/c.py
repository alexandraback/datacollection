#!/usr/bin/python -tt

import math


def isfair(n):
  s = str(n)
  if s == s[::-1]: return 1
  return 0

def main(A,B):
  total = 0
  sa = int(math.sqrt(A))
  sb = int(math.sqrt(B))
  if sa*sa < A: sa = sa + 1

  for i in xrange(sa,sb+1):
    if isfair(i):
      if isfair(i*i): total += 1
      #if isfair(i*i): total += 1; print i,i*i
  return total


if __name__ == '__main__':
  import sys
  T = int(sys.stdin.readline())
  for i in xrange(T):
    A,B = map(int,sys.stdin.readline().strip().split(" "))
    res = main(A,B)
    print "Case #%d: %s" % (i + 1, res)
