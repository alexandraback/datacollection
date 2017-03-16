#!/usr/bin/python -tt
# Yogen
# GCJ a3
# May 12

def fun(name,n):
 aei = ['a','e','i','o','u']
 tmp = name
 ret= 0
 while len(tmp) >= n:
  nc = 0
  for wrd in tmp:
   if wrd not in(aei):
    nc+=1
    if(nc==n): 
     ret+=1
     break
   else:
    nc = 0
  tmp = tmp[:-1]
 return ret
ncase = int(raw_input())

for each in range(ncase):
 print 'Case #%d:' %(each+1),
 name , n = map(str, raw_input().split())
 n = int(n)
 ans = 0

 tmp = name
 while len(tmp) >= n:
  ans+=fun(tmp,n)
  tmp = tmp[1:]

 print ans
