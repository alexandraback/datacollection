#!/usr/bin/python
import numpy as np
import scipy
import os,sys,re
from copy import deepcopy,copy
f=open(sys.argv[1],'r')
ncases = int(f.readline().strip())
for icase in xrange(ncases):
  dat=f.readline().strip().split()
  word=dat[0]
  n=int(dat[1])
  l=len(word)
  ans={}
  for m in re.finditer("(?=[b,c,d,f,g,h,j,k,l,m,n,p,q,r,s,t,v,w,x,y,z]{"+str(n)+"})",word):
    #Move right counter to end
    rctr=m.start()+n
    while rctr<=l:
      lctr=m.start()
      while lctr>=0:
        if (lctr,rctr) not in ans:
          ans[(lctr,rctr)]=1
        lctr=lctr-1
      rctr=rctr+1
  ans=len(ans)
  print "Case #%d: %d"%(icase+1,ans)


