#!/usr/bin/python

import sys

numcases=int(sys.stdin.readline())
for j in range(numcases):
  n=int(sys.stdin.readline())
  lin=sys.stdin.readline().split()
  naomi=[]
  for wt in lin:
    naomi.append(float(wt))
  lin=sys.stdin.readline().split()
  ken=[]
  for wt in lin:
    ken.append(float(wt))
  naomi.sort()
  ken.sort()
  allwts=[]
  for wt in naomi:
    allwts.append((wt,"n"))
  for wt in ken:
    allwts.append((wt,"k"))
  allwts.sort()
  allwts.reverse()
  maxscore=0
  minscore=0
  curscore=0
  for wt,person in allwts:
    if person=="n":
      curscore+=1
      if curscore>maxscore:
        maxscore=curscore
    else:
      curscore-=1
      if curscore<minscore:
        minscore=curscore
  sys.stdout.write("Case #"+repr(j+1)+": "+repr(n+minscore)+" "+repr(maxscore)+"\n")
