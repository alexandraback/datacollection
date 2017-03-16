import sys
import math
import pdb

def docase(f,casenum):
  data = f.next().split()
  X = int(data[0])
  Y = int(data[1])
  result = ""
  if X > 0:
    result += "WE"*X
  else:
    result += "EW"*(-X)
  if Y > 0:
    result += "SN"*Y
  else:
    result += "NS"*(-Y)
  print "Case #" + str(casenum) + ": " + result

with open(sys.argv[1],"r") as f:
  T = int(f.next())
  for k in xrange(T):
    docase(f,k+1)