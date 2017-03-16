#!/usr/bin/python

import sys

def processCase(case):
   C,F,X = [float(x) for x in sys.stdin.readline().split()]
   
   T = 0
   N = 0
   while True:
      Tx = X/(2+F*N) #stay the course
      TNp = C/(2 + F*N)
      TNpX = TNp + X/(2+F*(N+1)) #add another farm

      #print N,T,Tx,TNp,TNpX
      
      if Tx < TNpX:
         #if we should stay the course, we're done
         print "Case #%d: %0.7f" % (case+1,T+Tx)
         return
      else:
         N += 1
         T += TNp


num = int(sys.stdin.readline())

for case in range(0,num):
    processCase(case)
