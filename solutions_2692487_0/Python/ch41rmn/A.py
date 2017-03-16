#!/usr/bin/python

import os,sys,string

def absorb_n(x,y):
  count=0
  new_x=x
  while ( new_x <= y ):
    new_x+=(new_x-1)
    count+=1
  return [count,new_x-x]


fname=sys.argv[1]
fhandle=open(fname,"r")

ncases=int(fhandle.readline())

for case in range(ncases):
  prefix="Case #"+str(case+1)+": "

  [ A , N ]=[int(i) for i in fhandle.readline().rstrip().split(" ")]

  a=[int(i) for i in fhandle.readline().rstrip().split(" ")]

  if A==1:
    answer=N
  else:
    a.sort()
    c=[0]*(N+1)
    c[0]=A
    for i in range(N):
      c[i+1]=c[i]+a[i]
    answer=0
    worst_case=N
    debit=0
    for i in range(N):
      if (c[i] <= a[i]):
        [count,dx]=absorb_n(c[i],a[i])
        if worst_case<=count:
          answer+=worst_case
          break
        else:
          worst_case-=count
          debit+=(count-1)
          answer+=count
          for j in range(i,N+1):
            c[j]+=dx
      else:
        if debit>0:
          debit-=1
        else:
          worst_case-=1
        if worst_case==0:
          break
  print prefix+str(answer) 
