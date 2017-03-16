#!/usr/bin/env python

import sys

def deceitful_war(N, K):
  points = 0
  while N and K:
    if N[-1] > K[-1]:
      points += 1
      N.pop()
      K.pop()
    else:
      N.pop(0)
      K.pop()

  return points

def optimal_war(N,K):
   points = 0
   for n in N:
     if n > K[-1]:
       points += 1
       K.pop(0)
     else:
       for i in range(len(K)):
         if K[i] > n:
           K.pop(i)
	   break

   return points 

T = int(sys.stdin.readline())

for t in range(T):
  sys.stdin.readline()

  N = sorted(map(float, sys.stdin.readline().split()))
  K = sorted(map(float, sys.stdin.readline().split()))

  print ("Case #%d: %d %d") % ((t+1), deceitful_war(list(N), list(K)), optimal_war(sorted(list(N), reverse=True),list(K)))
