#!/usr/bin/python

import sys
numcases=int(sys.stdin.readline())
for j in range(numcases):
  lin=sys.stdin.readline().split()
  c=float(lin[0])
  f=float(lin[1])
  x=float(lin[2])
  secs=0.0
  k=0
  while (c/(2+k*f)+x/(2+(k+1)*f))<x/(2+k*f):
    secs+=c/(2+k*f)
    k+=1
  secs+=x/(2+k*f)
  sys.stdout.write("Case #"+repr(j+1)+": "+repr(secs)+"\n")
