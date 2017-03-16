import sys
import itertools
import numpy as np
import math
from copy import copy,deepcopy
f=open(sys.argv[1],'r')
ncases=int(f.readline().strip('\n'))
def get_orderings(chests,keys,remaining,order=[]):
  ordering=[]
  #Try opening next in sequence
  nremaining=[]
  for i in xrange(len(remaining)):
    r=remaining[i]
    if chests[r][0] in keys:
      #Change keys
      for k in chests[r][1]:
        if k in keys:
          keys[k]=keys[k]+1
        else:
          keys[k]=1
      #Remove the one I used
      k=chests[r][0]
      if keys[k]==1:
        del keys[k]
      else:
        keys[k]=keys[k]-1
      #Record that I opened it
      order.append(r)
    else:
      #Blast, can't do this one.
      nremaining.append(r)
  if len(nremaining)==0:
    #Finished!
    pass
  elif len(nremaining)==len(remaining):
    #Didn't open any new, so fail!
    pass
    
  
  
def aget_orderings(chests,keys,order=[]):
  #Are we done?
  if len(chests)==0:
    return [order]
  ordering=[]
  #Which ones can I open now?
  can_open=[]
  which_keys=[]
  for k in keys.keys():
    #Do we have the key and is there a chest to open with it?
    if keys[k]!=0 and k in chests:
      can_open.extend(chests[k].keys())
      which_keys.extend([k for i in xrange(len(chests[k]))])
  #Have we failed?
  if len(can_open)==0:
    return []
  which_keys=np.array(which_keys)[np.argsort(can_open)]
  can_open.sort()
  #Open the smallest one possible first
  for i in xrange(len(can_open)):
    cno=can_open[i]
    kno=which_keys[i]
    nkeys=deepcopy(keys)
    nchests=deepcopy(chests)
    norder=deepcopy(order)
    #Is this an easy chest?
    easy=kno in nchests[kno][cno]
    #Remove the key
    nkeys[kno]=nkeys[kno]-1
    #Add the new keys
    for j in nchests[kno][cno]:
      if j in nkeys:
        nkeys[j]=nkeys[j]+1
      else:
        nkeys[j]=1
    #Remove the chest
    del nchests[kno][cno]
    if len(nchests[kno])==0:
      del nchests[kno]
    #Record which one I opened
    norder.append(cno)
    #Open up further
    if not easy:
      ordering.extend(get_orderings(nchests,nkeys,norder))
  return ordering
    

for icase in xrange(ncases):
  K,N=[int(x) for x in f.readline().strip().split()]
  dat=np.array([int(x) for x in f.readline().strip().split()])
  keys={}
  for key in dat:
    if key in keys:
      keys[key]=keys[key]+1
    else:
      keys[key]=1
  null={}
  easy={}
  hard={}
  chests={}
  allkeys=[x for x in dat]
  for i in xrange(N):
    dat = [int(x) for x in f.readline().strip().split()]
    Ti,Ki = dat[:2]
    allkeys.extend(dat[2:])
    ckeys=dict(itertools.izip(dat[2:],np.repeat(1,Ki)))
    #0 = null, 1=easy, 2 =hard
    if Ki==0:
      flag=0
    elif Ti in ckeys:
      flag=1
    else:
      flag=2
    chests[i]=[Ti,flag,ckeys]
#Get the ordering
    #ckeys=dat[2:]
    #if Ki==0:
    #  if Ti in null:
    #    null[Ti][i]=ckeys
    #  else:
    #    null[Ti]={i:ckeys}
    #elif Ti in ckeys:
    #  if Ti in easy:
    #    easy[Ti][i]=ckeys
    #  else:
    #    easy[Ti]={i:ckeys}
    #else:
    #  if Ti in hard:
    #    hard[Ti][i]=ckeys
    #  else:
    #    hard[Ti]={i:ckeys}
    #if Ti in chests:
    #  chests[Ti][i]=ckeys
    #else:
    #  chests[Ti]={i:ckeys} 
  allkeys=list(np.unique(allkeys))
  #Convert each chest to a key chain
  mat=np.zeros((N+1,len(allkeys)+2))
  mat[:,-1]=np.arange(N+1)
  #Load first line
  for k in keys.keys():
    mat[0,allkeys.index(k)]=keys[k]
  #Now the rest
  for i in xrange(N):
    mat[i+1,-2]=allkeys.index(chests[i][0])
    for k in chests[i][2].keys():
      mat[i+1,allkeys.index(k)]=chests[i][2][k]
    mat[i+1,allkeys.index(chests[i][0])]=mat[i+1,allkeys.index(chests[i][0])]-1
  #print mat
  marker=1
  keychain=mat[0,:-2]
  #Add a bad rows column
  mat=np.c_[mat,np.zeros((mat.shape[0],1))]
  fail=np.any(np.sum(mat[:,:-3],0)<0)
  if fail:
    #print "Non-starter.",
    #print mat,np.sum(mat[:,:-3],0)
    print "Case #%d: IMPOSSIBLE"%(icase+1)
    continue
  while marker<(N+1):
    #Move down one at a time until we finish or we encounter a problem
    if keychain[mat[marker,-3]]>0:
      keychain=keychain+mat[marker,:-3]
      #Reset if we pass a bad chest
      if mat[marker,-1]==1:
        mat[marker,-1]=0
      marker=marker+1
        
    #Something went wrong
    else:
      #Try and bring something up first
      o=np.where((mat[(marker+1):,mat[marker,-3]]>0) & (mat[(marker+1):,-1]==0))[0]
      if len(o)!=0:
        #Bring up the one with the smallest index
        newpos=marker+1+o
        newpos=newpos[np.argmin(mat[newpos,-2])]
        #Move it here, marks as bad and try and continue
        mat[marker,-1]=1.
        #mat=np.r_[mat[:marker,],mat[(marker+1):(newpos+1)],mat[marker:(marker+1),],mat[(newpos+1):,]]
        mat=np.r_[mat[:marker,],mat[newpos:(newpos+1),],mat[(marker):(newpos)],mat[(newpos+1):,]]
        #print "Shuffling %d"%(marker)
        marker=1
        keychain=mat[0,:-3]
        continue
      else:
        #Balls, there's nothing to bring up, try sending problem fucker up instead
        if icase==19:
          pass
        #print "Balls"
        o=np.where((mat[:marker,mat[marker,-3]]<0) & (mat[:marker,-1]==0))[0]
        if len(o)!=0:
          #Want to move up as long as it's favourable to do so (lexicongraphically)
          cind=mat[marker,-2]
          for oo in o[::-1]:
            if np.any(mat[oo:marker,-2])<cind:
              break
          newpos=oo
          #mat[marker,-1]=2.
          mat=np.r_[mat[:newpos,],mat[marker:(marker+1),],mat[newpos:marker,],mat[(marker+1):,]]
          #print "Restart %d"%marker
          marker=1
          keychain=mat[0,:-3]
        else:
          #Superballs, we failed
          #print mat,np.sum(mat[:,:-3],0)
          fail=True
          break
  #print mat
  if not fail:
    #Post success shuffle
    oldmat=np.zeros(mat.shape)
    while np.any(oldmat!=mat):
      oldmat=copy(mat)
      for i in xrange(1,N+1):
        #Optimise slot i
        for j in xrange(1,int(mat[i,-2])):
          #Is j below me?
          o=i+np.where(mat[i:,-2]==j)[0]
          if len(o)==0:
            continue
          #Can it be brought up?
          tmat=np.r_[mat[:i,],mat[o:(o+1),],mat[(i):o,],mat[(o+1):,]]
          keychain=tmat[0,:-3]
          marker=1
          while marker<(N+1):
            #Move down one at a time until we finish or we encounter a problem
            if keychain[tmat[marker,-3]]<=0:
              break
            keychain=keychain+tmat[marker,:-3]
            marker=marker+1
          #This one worked!
          if marker==N+1:
            mat=tmat
            break
  if fail:
    print "Case #%d: IMPOSSIBLE"%(icase+1)
  else:
    print "Case #%d: %s"%(icase+1,(' '.join([str(int(x)) for x in mat[1:,-2]])))
