#!/usr/bin/python

from sys import stdin as I

def help(x):
  if x == 1:
    return 1
  if x == 2:
    return 10
  return help(x-1) + 10**((x-1)/2) + 10**((x-1)-(x-1)/2) - 1

def testcase():
  N = int(I.readline())
  if N < 10:
    return N
  
  S = str(N)
  L = len(S)
  L1 = N - 10**(L-1)
  L2 = int(S[:L/2][::-1]) + int(S[L/2:])
  if int(S[L/2:]) == 0:
    L2 = int(str(int(S[:L/2])-1)[::-1]) + 10**len(S[L/2:])
  return help(L) + min(L1, L2)

T = int(I.readline())
for t in range(T):
  print("Case #%i: %s" % (t+1, str(testcase())))
