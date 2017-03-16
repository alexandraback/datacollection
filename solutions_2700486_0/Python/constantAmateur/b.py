#!/usr/bin/python
import numpy as np
import scipy
import os,sys
from copy import deepcopy,copy
f=open(sys.argv[1],'r')
ncases = int(f.readline().strip())
def prXY(N,samplings=200):
  prob={}
  for i in xrange(samplings):
    d=dropNBricks(N)
    for k,v in d.iteritems():
      if k in prob:
        prob[k]=prob[k]+1./samplings
      else:
        prob[k]=1./samplings
  return prob


def dropNBricks(N):
  posns={}
  moveLeft=np.random.rand(N)<.5
  move=np.ones(N)
  move[moveLeft]=-1.
  #Dumb way for small N
  nleft=nright=0
  for i in xrange(N):
    if i==0:
      posns[(0,0)]=1.
    elif i==1:
      posns[(move[i]*2,0)]=1.
    elif i==2:
      if move[i]==move[i-1]:
        posns[(move[i],1)]=1.
      else:
        posns[(move[i]*2,0)]=1.
    elif i==3:
      if (move[i-1],1) in posns:
        posns[(-2*move[i-1],0)]=1.
      else:
        posns[(move[i],1)]=1.
    elif i==4:
      if (1,1) in posns:
        posns[(-1,1)]=1.
      else:
        posns[(1,1)]=1.
    elif i==5:
      posns[(2,0)]=1.
    elif i==6:
      posns[(4*move[i],0)]=1.
      if moveLeft[i]:
        nleft=nleft+1
      else:
        nright=nright+1
    elif i>6 and i<14:
      if nleft==4 and moveLeft[i]:
        moveLeft[i]=False
      elif nright==4 and not moveLeft[i]:
        moveLeft[i]=True
      if moveLeft[i]:
        posns[(-4+nleft,nleft)]=1.
        nleft=nleft+1
      else:
        posns[(4-nright,nright)]=1.
        nright=nright+1
    elif i==14:
      posns[(4,0)]=1.
      nleft=0
      nright=0
    elif i>15:
      if moveLeft[i]:
        posns[(-6+nleft,nleft)]=1.
        nleft=nleft+1
      else:
        posns[(6-nright,nright)]=1.
        nright=nright+1
  return posns

for icase in xrange(ncases):
  N,X,Y = [int(x) for x in f.readline().strip().split()]
  est=prXY(N)
  if (X,Y) in est:
    p=est[(X,Y)]
  else:
    p=0.
  if N<6:
    npos=2
  if N>6 and N<15:
    npos=4
  if N>15:
    npos=5
  pos=[0.]
  npos=7
  last_level=[]
  for n in xrange(npos):
    pos.append(.5**n)
    for l in last_level:
      pos.append(l+.5**n)
    last_level=copy(pos)
  #Round
  pos=np.array(pos)
  p=pos[np.argmin(np.abs(pos-p))]
  if p!=0. and p!=1.:
    est=prXY(N,20000)
  if (X,Y) in est:
    p=est[(X,Y)]
  else:
    p=0.
  p=pos[np.argmin(np.abs(pos-p))]
  #print "Case #%d: %f"%(icase+1,round(p*8,0)/8.)
  print "Case #%d: %f"%(icase+1,p)

