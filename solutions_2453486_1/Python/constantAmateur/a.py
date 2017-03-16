import sys
import itertools
import numpy as np
import math
from copy import copy
f=open(sys.argv[1],'r')
ncases=int(f.readline().strip('\n'))
#0=None
#1=X
#2=O
#3=T
map={}
map['.']=0
map['X']=1
map['O']=2
map['T']=3
for icase in xrange(ncases):
  grid=np.zeros((4,4))
  for i in xrange(4):
    grid[i,]=[map[c] for c in f.readline().strip()]
  null=f.readline()
  over=np.all(grid!=0)
  Xwon=False
  Owon=False
  #Check the rows
  for i in xrange(4):
    #Xwon?
    if np.sum(np.logical_or(grid[i,]==1,grid[i,]==3))==4:
      Xwon=True
    if np.sum(np.logical_or(grid[i,]==2,grid[i,]==3))==4:
      Owon=True
  #Check the columns
  for i in xrange(4):
    #Xwon?
    if np.sum(np.logical_or(grid[:,i]==1,grid[:,i]==3))==4:
      Xwon=True
    if np.sum(np.logical_or(grid[:,i]==2,grid[:,i]==3))==4:
      Owon=True
  #Check diagonals
  if grid[0,0] in [1,3] and grid[1,1] in [1,3] and grid[2,2] in [1,3] and grid[3,3] in [1,3]:
    Xwon=True
  if grid[0,0] in [2,3] and grid[1,1] in [2,3] and grid[2,2] in [2,3] and grid[3,3] in [2,3]:
    Owon=True
  if grid[0,3] in [1,3] and grid[1,2] in [1,3] and grid[2,1] in [1,3] and grid[3,0] in [1,3]:
    Xwon=True
  if grid[0,3] in [2,3] and grid[1,2] in [2,3] and grid[2,1] in [2,3] and grid[3,0] in [2,3]:
    Owon=True
  if Xwon and Owon:
    print "Case #%d: Draw"%(icase+1,)
  elif Xwon:
    print "Case #%d: X won"%(icase+1,)
  elif Owon:
    print "Case #%d: O won"%(icase+1,)
  else:
    if over:
      print "Case #%d: Draw"%(icase+1,)
    else:
      print "Case #%d: Game has not completed"%(icase+1,)
