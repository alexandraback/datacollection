#!/usr/bin/python
import sys
sys.setrecursionlimit(10000)

def osmos(armin, blobs, i=0):
    #print armin, blobs
    if i >= len(blobs):
        return 0
    nxt = blobs[i]
    
    if nxt < armin:
        return osmos(armin + nxt, blobs, i+1)
    elif armin == 1:
        return 1 + osmos(armin, blobs, i+1)
    else:
        return 1 + min(osmos(2*armin - 1, blobs, i), osmos(armin, blobs, i+1))
    
cases = int(raw_input())
for i in range(cases):
   l1 =  raw_input()
   armin = int(l1.split()[0])
   blob = raw_input()
   blobs = sorted([int(x) for x in blob.split()])
   s = osmos(armin, blobs)
   print "Case #%d: %d" % (i+1, s)
