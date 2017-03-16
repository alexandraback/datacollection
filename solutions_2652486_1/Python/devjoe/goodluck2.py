#!/usr/bin/python
#
# Good Luck - Google Code Jam 2013 Round1A C (second set)

import sys

fact=[1]
for i in range(1,13):
  fact.append(fact[-1]*i)
def comb(x):
  #compute the number of ways to generate x
  c2=x.count(2)
  c3=x.count(3)
  c4=x.count(4)
  c5=x.count(5)
  c6=x.count(6)
  c7=x.count(7)
  c8=x.count(8)
  return fact[12]/fact[c2]/fact[c3]/fact[c4]/fact[c5]/fact[c6]/fact[c7]/fact[c8]

inp=sys.stdin
t=int(inp.readline()) #always 1
print "Case #1:"
lin=inp.readline().split()
r=int(lin[0])
n=int(lin[1])
m=int(lin[2])
k=int(lin[3])
#precalculate results for 12 numbers
res={}
for n1 in range(2,m+1):
  prod1={}
  prod1[1]=0
  prod1[n1]=0
  for n2 in range(n1,m+1):
    prod2=prod1.copy()
    for p in prod1.keys():
      prod2[p*n2]=0
    for n3 in range(n2,m+1):
      prod3=prod2.copy()
      for p in prod2.keys():
        prod3[p*n3]=0
      for n4 in range(n3,m+1):
        prod4=prod3.copy()
        for p in prod3.keys():
          prod4[p*n4]=0
        for n5 in range(n4,m+1):
          prod5=prod4.copy()
          for p in prod4.keys():
            prod5[p*n5]=0
          for n6 in range(n5,m+1):
            prod6=prod5.copy()
            for p in prod5.keys():
              prod6[p*n6]=0
            for n7 in range(n6,m+1):
              prod7=prod6.copy()
              for p in prod6.keys():
                prod7[p*n7]=0
              for n8 in range(n7,m+1):
                prod8=prod7.copy()
                for p in prod7.keys():
                  prod8[p*n8]=0
                for n9 in range(n8,m+1):
                  prod9=prod8.copy()
                  for p in prod8.keys():
                    prod9[p*n9]=0
                  for n10 in range(n9,m+1):
                    prod10=prod9.copy()
                    for p in prod9.keys():
                      prod10[p*n10]=0
                    for n11 in range(n10,m+1):
                      prod11=prod10.copy()
                      for p in prod10.keys():
                        prod11[p*n11]=0
                      for n12 in range(n11,m+1):
                        prod12=prod11.copy()
                        for p in prod11.keys():
                          prod12[p*n12]=0
                        d=(n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12)
                        res[d]=[comb(d),prod12]
#try sets in descending order of likelihood, and 
#output the first match
reskeys=res.keys()
reskeys.sort(reverse=True)
for trial in xrange(r):
  vec=inp.readline().split()
  prods=[]
  for i in xrange(k):
    prods.append(int(vec[i]))
  best=0
  for ky in reskeys:
    ok=True
    for p in prods:
      if not res[ky][1].has_key(p):
        ok=False
        break
    if ok:
      best=ky
      break
  output=""
  for j in best:
    output+=repr(j)
  print output

      
