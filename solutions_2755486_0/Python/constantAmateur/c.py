#!/usr/bin/python
import numpy as np
import scipy
import os,sys
from copy import deepcopy,copy
sys.setrecursionlimit(10000)
f=open(sys.argv[1],'r')
f=open("C-small-attempt0.in")
ncases = int(f.readline())
def nextAttack(ftribes):
  nday=np.inf
  for t in ftribes:
    if t[0]<nday:
      nday=t[0]
  if nday==np.inf:
    nday=-1
  return nday
  

print ncases
for icase in xrange(ncases):
  N=int(f.readline().strip())
  tribes=[]
  wall={}
  day=0
  cnt=0
  for i in xrange(N):
    tribes.append([int(x) for x in f.readline().strip().split()])
  #Format is (next_attack_day, nattacks_left,west_attack,east_attack,strength,_,_,_)
  ftribes=copy(tribes)
  nday=nextAttack(ftribes)
  #Process day
  while nday>=0:
    #print nday,ftribes,wall,cnt
    #First see which tribes attack today
    atribes=[x for x in ftribes if x[0]==nday]
    #See which tribes win
    dwall={}
    for t in atribes:
      win=0
      for x in xrange(t[2],t[3]+1):
        if x!=t[3]:
          if x in wall and x+.5 in wall and wall[x]>=t[4] and wall[x+.5]>=t[4]:
            pass
          else:
            win=1
            break
        else:
          if x in wall and wall[x]>=t[4]:
            pass
          else:
            win=1
            break
            win=0
      #Update the wall
      for x in xrange(t[2],t[3]+1):
        dwall[x]=max(t[4],wall[x] if x in wall else 0,dwall[x] if x in dwall else 0)
        if x!=t[3]:
          dwall[x+.5]=max(t[4],wall[x+.5] if x+.5 in wall else 0,dwall[x+.5] if x+.5 in dwall else 0)
      cnt=cnt+win
    #All attacks done, now update the wall
    wall.update(dwall)
    #Move all the tribes which attacked
    dead=[]
    for i in xrange(len(ftribes)):
      t=ftribes[i]
      if t[0]!=nday:
        continue
      #See if it's done
      if t[1]==1 or (t[4]<=0 and t[-1]<=0):
        dead.append(i)
        continue
      ftribes[i][1]=ftribes[i][1]-1
      #New attack day
      ftribes[i][0]=ftribes[i][0]+ftribes[i][-3]
      #New west
      ftribes[i][2]=ftribes[i][2]+ftribes[i][-2]
      #New east
      ftribes[i][3]=ftribes[i][3]+ftribes[i][-2]
      #New stregth
      ftribes[i][4]=ftribes[i][4]+ftribes[i][-1]
    #Delete in order that doesn't fuck up indicies of next delete
    for i in dead[::-1]:
      del ftribes[i]
    nday=nextAttack(ftribes)
  print "Case #%d: %d"%(icase+1,cnt)

