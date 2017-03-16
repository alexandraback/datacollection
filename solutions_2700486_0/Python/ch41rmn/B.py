#!/usr/bin/python

import os,sys,string

def get_base(X,Y):
  return (abs(X)+abs(Y))+1

def get_stack(X,Y):
  return (Y+1)

def binomial(n,r):
  n_iterate=r
  if (n-r)<r:
    n_iterate=n-r
  numerator=1
  denominator=1
  upper=n
  lower=1
  for i in range(n_iterate):
    numerator*=upper
    denominator*=lower
    upper-=1
    lower+=1
  return numerator/denominator

fname=sys.argv[1]
fhandle=open(fname,"r")

ncases=int(fhandle.readline())

for case in range(ncases):
  prefix="Case #"+str(case+1)+": "

  [N,X,Y]=[int(dim) for dim in fhandle.readline().split(" ")]

  i=1
  base=1
  nT=1
  while nT<=N:
    base+=2
    nT=base*(1+base)/2
  base-=2
  nT=base*(1+base)/2

  shell=base+2
  full_stack=shell-1

  dN=N-nT

  probe_height=get_stack(X,Y)
  probe_base=get_base(X,Y)

  answer=0.0

  if probe_base<=base:
    # we are part of the base triangle! always filled
    answer=1.0
  elif probe_height==full_stack+1:
    # this case is also impossible
    answer=0.0
  elif probe_base==shell:
    # we are part of the next shell.
    if dN<=full_stack:
      # we don't have enough to fully stack one side!
      if dN>=probe_height: # do we have enough to reach the probe?

        for i in range(probe_height,dN+1):
          answer += binomial(dN,i)*(0.5**dN)
    else:
      # we could fully stack one side!
      dN_2=dN-full_stack # if we fully stack one side, this much is left
      min_height=dN_2 # this is also the minimum stack of the sides

      # by fully stacking the other side,
      if dN_2>=probe_height: # do we have enough to reach the probe?
        answer += (0.5**shell)
      
      # if we didn't fully stack 
      if min_height>probe_height:
        for i in range(min_height,full_stack+1):
          answer += binomial(dN,i)*(0.5**dN)
      else:
        for i in range(probe_height,full_stack+1):
          answer += binomial(dN,i)*(0.5**dN)

  else:
    # we are not near the base triangle. never filled.
    answer=0.0

  print prefix+str(answer)
