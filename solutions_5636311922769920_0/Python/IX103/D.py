#!/usr/bin/python

import sys
import math

def processCase(case):
   K,C,S =  [int(x) for x in sys.stdin.readline().split()]
   
   numSrequired = int(math.ceil(float(K)/C))
   if S < numSrequired:
     print "Case #%d: IMPOSSIBLE" % (case,)
   else:
     testpoints = []
     for s in range(0,numSrequired):
       point = 0
       for c in range(0,C):
         #print point
         offset = (s*C+c) % K
         #print offset
         point += offset*K**(C-c-1)
         #print offset*K**(C-c-1)
       testpoints.append(str(point+1))
     print "Case #%d: " % (case,) + " ".join(testpoints)

   
num = int(sys.stdin.readline())

for case in range(1,num+1):
    processCase(case)
