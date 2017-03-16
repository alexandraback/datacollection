#!/usr/bin/python

import sys

T = int(sys.stdin.readline())
for t in range(T):
  N = int(sys.stdin.readline())
  A = []
  B = []

  for i in range(N):
    toks = sys.stdin.readline().strip().split()
    A.append(int(toks[0]))
    B.append(int(toks[1]))

  #print N,A,B

  L = [0]*N
  l = 0
  steps = 0

  while (l<2*N):
    foundwin=False

    # check for 2-star wins
    for i in range(N):
      if (L[i]<2 and l>=B[i]):
        l+=2-L[i]
        L[i]=2
        steps+=1
        foundwin=True
        #print "B",i

    if foundwin:
      continue

    # check for 1-star wins
    bi=-1
    bb=0
    for i in range(N):
      if (L[i]<1 and l>=A[i]):
        if (B[i]>bb):
          bi=i
          bb=B[i]
    if (bi!=-1):
      l+=1
      L[bi]=1
      steps+=1
      foundwin=True
      #print "A",bi

    if (not foundwin and l<2*N):
      steps=-1
      break


  if (steps>0):
    print "Case #%d: %d" % (t+1,steps)
  else:
    print "Case #%d: Too Bad" % (t+1)

