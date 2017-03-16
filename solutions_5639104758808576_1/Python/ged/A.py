#!/usr/bin/python
import sys

inp = [l.strip() for l in sys.stdin]
T = int(inp[0])
l = 1
for t in range(T):
  line = inp[l]
  Smax = int(line.split(" ")[0])
  ss = [int(c) for c in (line.split(" ")[1])]

  #print ss
  standing = 0
  added = 0
  for i in range(len(ss)):
    toadd = max(0, i-standing)
    added += toadd
    #print "shy=%d, cnt=%d, adding=%d standing=%d" % (i, ss[i], toadd, standing)
    standing += ss[i]+toadd
    
  l += 1
  #print Smax, ss, added
  print "Case #%d: %s" % (t+1, added)

