import sys
import itertools
import numpy as np
import math
from copy import copy
f=open(sys.argv[1],'r')
ncases=int(f.readline().strip('\n'))
for icase in xrange(ncases):
  N,M=[int(x) for x in f.readline().strip().split()]
  grid=np.zeros((N,M))
  lawn=np.empty((N,M))
  lawn.fill(100)
  for i in xrange(N):
    grid[i,]=[int(x) for x in f.readline().strip().split()]
  #First trim all to the highest level
  lawn.fill(np.max(grid))
  heights=np.unique(grid)
  heights.sort()
  heights=heights[::-1]
  #Do the next highest next, if we can
  ii=1
  lost=False
  while ii<len(heights):
    h=heights[ii]
    #Move along, trimming where possible
    for i in xrange(N):
      if np.all(grid[i,]<=h):
        lawn[i,]=h
    for i in xrange(M):
      if np.all(grid[:,i]<=h):
        lawn[:,i]=h
    #Did we do all we need
    o=np.where(grid>=h)
    if np.any(grid[o]!=lawn[o]):
      lost=True
      break
    ii=ii+1
  if lost or np.any(grid!=lawn):
    print "Case #%d: NO"%(icase+1,)
  else:
    print "Case #%d: YES"%(icase+1,)
