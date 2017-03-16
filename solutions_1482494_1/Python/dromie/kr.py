#!/usr/bin/python
import math
import sys

input = open (sys.argv[1],'r')
T = int(input.readline())
for t in range(0,T):
  N = int(input.readline())
  L = []
  for l in range(N):
    L.append(map(int,input.readline().rstrip().split(' ')))
  LL = []
  for i in range(len(L)):
    LL.append([[L[i][0],1,i],[L[i][1],2,i]])
  C = 0
  P = 0
  while len(LL)>0:
    maxl=None
    level2=False
    for l in LL:
      if l[1][0]<=C:
        if level2:
          if maxl[1][1]<l[1][1]:
            maxl=l
            level2=True
        else:
            maxl=l
            level2=True
      elif l[0][1]>0 and l[0][0]<=C and not level2:
        if maxl:
          if l[1][0]>=maxl[1][0]:
            maxl=l
        else:
          maxl=l
    if maxl!=None:
      P=P+1
      if maxl[1][0]<=C:
        C=C+maxl[1][1]
        LL.remove(maxl)
      else:
        C=C+1
        maxl[0][1]=0
        maxl[1][1]=1
    else:
      break
  if (len(LL)==0):
    print "Case #%d: %d" % (t+1,P)
  else:
    print "Case #%d: Too Bad"%(t+1)

