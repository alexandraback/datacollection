#!/usr/bin/python

from sys import stdin as I

def testcase():
  R, C, W = map(int, I.readline().split())

  if C % W == 0:
    return R * C / W + W - 1
  else:
    return R * C / W + W

T = int(I.readline())
for t in range(T):
  print("Case #%i: %s" % (t+1, str(testcase())))
