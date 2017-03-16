#!/usr/bin/python

from sys import stdin as I

def testcase():
  C, D, V = map(int, I.readline().split())
  Ds = map(int, I.readline().split())
  Ds.sort(reverse=True)
  res = 0

  N = 1
  while N <= V:
    if len(Ds) > 0:
      n = Ds[-1]
      if n <= N:
	N += n * C
	Ds.pop()
      else:
	res += 1
	N += N * C
    else:
      res += 1
      N += N * C

  return res

T = int(I.readline())
for t in range(T):
  print("Case #%i: %s" % (t+1, str(testcase())))
