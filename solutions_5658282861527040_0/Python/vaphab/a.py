#!/usr/bin/python
import os,sys
T=int(raw_input())
for t in range(T):
  [A, B, K] = ([int(e) for e in raw_input().split()])
  res = 0
  for a in range(A):
    for b in range(B):
      if a&b < K:
        res += 1

  print 'Case #'+str(t+1)+': '+str(res)

