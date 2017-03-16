#!/usr/bin/python
#
# Good Luck - Google Code Jam 2013 Round1A C (first set)

import sys

inp=sys.stdin
t=int(inp.readline()) #always 1
print "Case #1:"
lin=inp.readline().split()
r=int(lin[0])
n=int(lin[1])
m=int(lin[2])
k=int(lin[3])
#precalculate results for 3 numbers
res={}
for n1 in range(2,m+1):
  for n2 in range(2,m+1):
    for n3 in range(2,m+1):
      d=[n1,n2,n3]
      d.sort()
      d=tuple(d)
      if res.has_key(d):
        res[d][0]+=1
      else:
        prods=[1,n1,n2,n3,n1*n2,n1*n3,n2*n3,n1*n2*n3]
        res[d]=[1,prods]
for trial in xrange(r):
  vec=inp.readline().split()
  prods=[]
  for i in xrange(k):
    prods.append(int(vec[i]))
  best=0
  bestchance=0
  for ky in res.keys():
    ok=True
    for p in prods:
      if p not in res[ky][1]:
        ok=False
        break
    if ok and res[ky][0]>bestchance:
      best=ky
      bestchance=res[ky][0]
  output=""
  for j in best:
    output+=repr(j)
  print output

      
