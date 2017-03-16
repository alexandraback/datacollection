#!/usr/bin/python

import sys
import string

trans = string.maketrans("-+","+-")


def processCase(case):
   stack = list(sys.stdin.readline().strip())
   swapcount = 0
   for n in reversed(range(0, len(stack))):
     #print stack
     if stack[n] == '-':
       #check top
       lastt = n
       for t in range(0,n):
          if stack[t] != '+':
            lastt = t
            break
       if lastt > 0:
         #swap
         stack[0:lastt] = list(reversed("".join(stack[0:lastt]).translate(trans)))
         swapcount += 1
         #print "flop %d" % (lastt,)
       
       #swap
       stack[:n+1] = list(reversed("".join(stack[:n+1]).translate(trans)))
       swapcount += 1
       #print "flip"
     else:
       assert(stack[n] == '+')
   print "Case #%d: %d" % (case,swapcount)
   
num = int(sys.stdin.readline())

for case in range(1,num+1):
    processCase(case)
