import sys
import math

t = int(sys.stdin.readline())
cntr = 0
br = 2.0
for line in sys.stdin:
  cntr += 1
  line = line.split()
  c = float(line[0])
  f = float(line[1])
  x = float(line[2])
  num_farms = 0
  best = x / br
  elaps = 0.0
  while True:
    elaps += c / (br + num_farms*f)
    num_farms += 1
    cur = elaps + x / (br + num_farms*f)
    if cur < best:
      best = cur
    else:
      break
  print "Case #{0}: {1}".format(cntr, best) 
