import sys
from math import ceil, floor

def solve (pcakes):
  minutes = 0
  while (True):
    maxp = pcakes[0]
    maxc = 1
    maxp2 = 0
    for k in range(1,len(pcakes)):
      if pcakes[k] > maxp:
        maxp2 = maxp
        maxp = pcakes[k]
        maxc = 1
      elif pcakes[k] == maxp:
        maxc += 1
      elif pcakes[k] > maxp2:
        maxp2 = pcakes[k]
###    newmax = maxp/2 if maxp%2==0 else maxp/2+1
    newmax = max(maxp2, maxp/2 if maxp%2==0 else maxp/2+1)
    saved = maxp - newmax
    cost = maxc
    print "maxp= %i, maxp2= %i, newmax= %i" % (maxp,maxp2,newmax)
    print "splitting all %is saves %i at cost %i" % (maxp, saved, cost)
    if cost > saved:
      return minutes + maxp
    else:
      n = len(pcakes)
      for k in range(n):
        p = pcakes[k]
        if p == maxp:
          pcakes[k] = maxp/2
          pcakes.append(p-pcakes[k])
          minutes += 1
          print pcakes, minutes

def solve2 (pcakes):
  minutes = 0
  while (True):
    maxp = max(pcakes)
    maxp2 = 0
    for k in range(len(pcakes)):
      if pcakes[k] <= maxp-2 and pcakes[k] > maxp2:
        maxp2 = pcakes[k]
    cost = pcakes.count(maxp) + pcakes.count(maxp-1)
    newmax = max(maxp2, maxp/2 if maxp%2==0 else maxp/2+1)
    saved = maxp - newmax
#    print "maxp=%i, maxp2=%i, saved= %i, cost= %i" % (maxp,maxp2,saved,cost)
    if cost > saved:
      return minutes + maxp
    else:
      n = len(pcakes)
      for k in range(n):
        p = pcakes[k]
        if p == maxp or p == maxp-1:
          pcakes[k] = maxp/2
          pcakes.append(p-pcakes[k])
          minutes += 1
#          print pcakes, minutes
          
#test = [63,1]
#print test
#print solve2(test)
#sys.exit()

f = open(sys.argv[1],"r")
T = int(f.readline())
for case in range(1,T+1):
  D = int(f.readline())
  pcakes = map(int, f.readline().strip("\n").split())
#  print "\n>> Case #%i " % case, pcakes
#  print solve2(pcakes[:])
  print "Case #%i: %i" % (case, solve2(pcakes))
  
