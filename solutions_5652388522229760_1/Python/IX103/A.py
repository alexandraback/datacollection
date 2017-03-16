#!/usr/bin/python

import sys

def processCase(case):
   N = int(sys.stdin.readline())
   
   if N == 0:
     print "Case #%d: INSOMNIA" % (case,)
   else:
     current = N;
     cset = set()
     while (len(cset) < 10):
        cset |= set(str(current))
        current = N+current
     print "Case #%d: %d" % (case,current-N)

   
num = int(sys.stdin.readline())

for case in range(1,num+1):
   processCase(case)
