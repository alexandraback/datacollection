import sys
import math
import pdb

def docase(f,casenum):
  data = f.next().split()
  A = int(data[0])
  N = int(data[1])
  L = map(int,f.next().split())
  M = [False]*len(L)
  L.sort()
  cnt = 0
  idx = 0
  if A <= 1:
    cnt = len(L)
  else:
    while idx < len(L):
      while A <= L[idx]:
        L.insert(idx,A-1)
        M.insert(idx,True)
        A += A-1
        idx += 1
        cnt += 1
      A += L[idx]
      idx += 1
    idx = len(L)-1
    gives = 0
    added = 0
    while idx >= 0:
      while not M[idx] and idx >= 0:
        idx -= 1
        gives += 1
      while M[idx] and idx >= 0:
        idx -= 1
        added += 1
      if added > gives:
        cnt -= added
        cnt += gives
        added = 0
        gives = 0
  print "Case #" + str(casenum) + ": " + str(cnt)

with open(sys.argv[1],"r") as f:
  T = int(f.next())
  for k in xrange(T):
    docase(f,k+1)