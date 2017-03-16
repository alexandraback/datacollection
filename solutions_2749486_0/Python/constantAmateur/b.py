#!/usr/bin/python
import numpy as np
import scipy
import os,sys
from copy import deepcopy,copy
sys.setrecursionlimit(10000)
f=open(sys.argv[1],'r')
ncases = int(f.readline().strip())
def doMoves(starts,tgtX,tgtY,step=1):
  #Gone too far?
  if step>np.abs(tgtX)+np.abs(tgtY):
    return None
  #Reached the target?
  if starts[1]==tgtX and starts[2]==tgtY:
    return starts[0]
  #OK, so try moving somewhere
  #Pick the move which brings us closest to our goal
  dd=[]
  dd.append((tgtX-starts[1])**2+(tgtY-starts[2]+step)**2)
  dd.append((tgtX-starts[1])**2+(tgtY-starts[2]-step)**2)
  dd.append((tgtX-starts[1]+step)**2+(tgtY-starts[2])**2)
  dd.append((tgtX-starts[1]-step)**2+(tgtY-starts[2])**2)
  o=np.argsort(dd)
  for i in o:
    if i==0:
      a=doMoves((starts[0]+"N",starts[1],starts[2]+step),tgtX,tgtY,step+1)
      if a is not None:
        return a
    elif i==1:
      a=doMoves((starts[0]+"S",starts[1],starts[2]-step),tgtX,tgtY,step+1)
      if a is not None:
        return a
    elif i==2:
      a=doMoves((starts[0]+"E",starts[1]+step,starts[2]),tgtX,tgtY,step+1)
      if a is not None:
        return a
    else:
      a=doMoves((starts[0]+"W",starts[1]-step,starts[2]),tgtX,tgtY,step+1)
      if a is not None:
        return a

for icase in xrange(ncases):
  X,Y = [int(x) for x in f.readline().strip().split()]
  #print X,Y
  xx=0
  yy=0
  seq=''
  base='WE' if X>=0 else 'EW'
  seq=seq+base*int(abs(X)*1)
  ##First reach X
  #m=np.floor(.5*(-1+np.sqrt(8*abs(X)+1)))
  #seq=seq+base[1]*int(m)
  #xx=xx+.5*m*(m+1)*np.sign(X)
  #extra=2*(abs(X)-abs(xx))
  #xx=xx+np.sign(X)*extra*.5
  #seq=seq+base*int(extra)
  #Now reach Y
  base="SN" if Y>=0 else "NS"
  seq=seq+base*int(abs(Y)*1)
  print "Case #%d: %s"%(icase+1,seq)

