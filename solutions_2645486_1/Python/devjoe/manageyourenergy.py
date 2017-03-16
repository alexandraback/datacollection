#!/usr/bin/python
#
# Manage Your Energy - Google Code Jam 2013 Round1A B

import sys

def findtask(subs,task):
  #binary search to find the task
  if task<=subs[0][1]:
    return 0
  if task>=subs[-1][0]:
    return len(subs)-1
  lo=0
  hi=len(subs[-1])
  while lo+1<hi:
    md=int((lo+hi)/2)
    if task<subs[md][0]:
      hi=md
    elif task>subs[md][1]:
      lo=md
    else:
      return md
  if task>=subs[hi][0]:
    return hi
  if task<=subs[lo][1]:
    return lo
  #we really can't get here if the list is managed correctly
  return None

inp=sys.stdin
cases=int(inp.readline())
for case in xrange(cases):
  ern=inp.readline().split()
  e=int(ern[0])
  r=int(ern[1])
  n=int(ern[2])
  vvec=inp.readline().split()
  v=[]
  vsort=[]
  for i in xrange(n):
    v.append(int(vvec[i]))
    vsort.append((int(vvec[i]),i))
  vsort.sort(reverse=True)
  #list of subsets of the activities.
  #Each subset is marked by its first task number,
  #last task number, incoming energy, and exiting energy
  subs=[(0,n-1,e,r)]
  #list of assigned energies. -1 in this list means unknown
  energy=[-1]*n
  #go through tasks in order from most to least valuable,
  #assigning maximum possible energy to each one
  for taskval,task in vsort:
    #only if we have not already assigned this task 0 energy
    if energy[task]==-1:
      sid=findtask(subs,task)
      starttask,endtask,startenergy,endenergy=subs[sid]
      inenergy=min(e,startenergy+r*(task-starttask))
      outenergy=max(r,endenergy-r*(endtask-task))
      energy[task]=inenergy+r-outenergy
      #split up the subset appropriately
      if inenergy<e and outenergy>r:
        #all energy in this entire interval went to this task
        for i in xrange(starttask,task):
          energy[i]=0
        for i in xrange(task+1,endtask+1):
          energy[i]=0
        del subs[sid]
        if len(subs)==0:
          break
      elif inenergy<e:
        #use all energy from start, but still have energy later
        for i in xrange(starttask,task):
          energy[i]=0
        subs[sid]=(task+1,endtask,outenergy,endenergy)
      elif outenergy>r:
        #no energy left afterward, but still have excess energy before
        for i in xrange(task+1,endtask+1):
          energy[i]=0
        subs[sid]=(starttask,task-1,startenergy,inenergy)
      else:
        #excess energy on both ends
        subs[sid:(sid+1)]=[(starttask,task-1,startenergy,inenergy),
                           (task+1,endtask,outenergy,endenergy)]
  #Add up energy*value
  energyvalue=0
  for i in range(n):
    if energy[i]>0:
      energyvalue+=energy[i]*v[i]
  print "Case #"+repr(case+1)+": "+repr(energyvalue)
