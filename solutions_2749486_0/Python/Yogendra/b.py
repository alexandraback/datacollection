#!/usr/bin/python -tt
# Yogen
# GCJ a3
# May 12

ncase = int(raw_input())

for each in range(ncase):
 print 'Case #%d:' %(each+1),
 X , Y = map(int, raw_input().split())
 a=b=0
 n = 0
 ans ='' 
 while a != X: 
  n += 1
  flag = 0
  if X-a>=n:
   a+=n
   ans= ans+"E"
  else:
   a-=n
   flag = 0
   ans = ans+"W"
 while b != Y:
  n+=1
  if Y - b>= n:
   b+=n
   ans = ans+"N"
  else:
   b-=n
   ans = ans+"S"
 print ans
