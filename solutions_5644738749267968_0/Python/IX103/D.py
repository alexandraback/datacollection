#!/usr/bin/python

import sys
import bisect

def SolveDeceitful(Bn,Bk):
   #lists sorted in ascending order
   count = 0
   kidx = 0
   for n in Bn:
     if n > Bk[kidx]:
        kidx += 1
        count += 1
   return count
        

def SolveWar(Bn,Bk):

   #Try lightest first
   lcount = 0
   lBk = list(Bk)

   for n in Bn:
      gidx = bisect.bisect(lBk,n) #find next higher
      #print "%f %d" % (n,gidx)
      if gidx >= len(lBk): #if none higher, use lowest
         gidx = 0
      if n > lBk[gidx]:
         lcount += 1
      #print "n%f k%f g%d c%d" % (n,lBk[gidx],gidx,lcount)
      del lBk[gidx]
   
   #Try heaviest first
   hcount = 0
   hBk = list(Bk)
   for n in reversed(Bn):
      gidx = bisect.bisect(hBk,n) #find next higher
      #print "%f %d" % (n,gidx)
      if gidx >= len(hBk): #if none higher, use lowest
         gidx = 0
      if n > hBk[gidx]:
         hcount += 1
      #print "n%f k%f g%d c%d" % (n,hBk[gidx],gidx,hcount)
      del hBk[gidx]

   return max(hcount,lcount)
   

def processCase(case):
   N = int(sys.stdin.readline())
   Bn = set([float(x) for x in sys.stdin.readline().split()])
   Bk = set([float(x) for x in sys.stdin.readline().split()])
   
   assert(len(Bn)==N)
   assert(len(Bk)==N)
   assert(Bn.isdisjoint(Bk))
   
   Bn = list(sorted(Bn))
   Bk = list(sorted(Bk))
   
   bestDeceitful = SolveDeceitful(Bn,Bk)
   bestWar = SolveWar(Bn,Bk)
   
   print "Case #%d: %d %d" % (case+1,bestDeceitful,bestWar)

num = int(sys.stdin.readline())

for case in range(0,num):
    processCase(case)
