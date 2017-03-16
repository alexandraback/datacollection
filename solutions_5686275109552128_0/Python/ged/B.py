#!/usr/bin/python
import sys

inp = [l.strip() for l in sys.stdin]
T = int(inp[0])
l = 1
for t in range(T):
  D = int(inp[l])
  Ps = [int(x) for x in inp[l+1].split(" ")]
  Ps.sort()
  Ps=Ps[::-1]
  
  #print >> sys.stderr, "CASE ",t, Ps
  best = Ps[0]
  eating = bestE = Ps[0]
  bestS = 0
  while eating>0:
    #print >> sys.stderr, "*Eating ",eating, "mins?"
    splits = 0
    for i in range(D):
      if Ps[i]<=eating:
        break;
      #print >> sys.stderr, "item[",i,"]=",Ps[i],"needs to be split",(Ps[i]-1)/eating
      splits += (Ps[i]-1)/eating
      
    total = eating + splits
    if best>total:
      best = total
      bestS = splits
      bestE = eating
    #print >> sys.stderr, "* splits=",splits, "total: ",total
    eating-=1
  
  l += 2
  #print >> sys.stderr, "Case #%d: %d (eating=%d, split=%d)" % (t+1, best, bestE, bestS)
  print "Case #%d: %d" % (t+1, best)

