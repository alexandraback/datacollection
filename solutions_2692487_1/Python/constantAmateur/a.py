#!/usr/bin/python
import numpy as np
import scipy
import os,sys
from copy import deepcopy,copy
f=open(sys.argv[1],'r')
ncases = int(f.readline().strip())
for icase in xrange(ncases):
  A,N = [int(x) for x in f.readline().strip().split()]
  motes = np.array([int(x) for x in f.readline().strip().split()])
  if A==1:
    print "Case #%d: %d"%(icase+1,N)
    continue
  motes.sort()
  csum=np.cumsum(motes)
  nadd = np.zeros(N)
  ndel = np.zeros(N)
  #calculate the num to add to get to this point
  size=A
  for i in xrange(N):
    add=0
    while size <= motes[i]:
      size=size+(size-1)
      add=add+1
    size=size+motes[i]
    nadd[i]=add
  #Now see if we can save any by deleting
  #print nadd
  tmp=[0]+list(np.cumsum(nadd))
  n_need_del=N
  tot=np.sum(nadd)
  best=np.sum(nadd)
  for ninc in xrange(N):
    ndel=(N-ninc)
    newtot=ndel+tmp[ninc]
    if newtot<best:
      best=newtot
  print "Case #%d: %d"%(icase+1,best)


