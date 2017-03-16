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

  '''
  #precomputing
  precomputed = []
  for i in xrange(sa,sb+1):
    if isfair(i):
      #if isfair(i*i): total += 1
      if isfair(i*i): total += 1; print i,i*i; precomputed.append(i);
  print precomputed; precomputed=[];
  return total
  '''

  precomputed = [1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002]
  for i in precomputed:
    if sa <= i <= sb: total +=1
  return total


if __name__ == '__main__':
  import sys
  T = int(sys.stdin.readline())
  for i in xrange(T):
    A,B = map(int,sys.stdin.readline().strip().split(" "))
    res = main(A,B)
    print "Case #%d: %s" % (i + 1, res)
