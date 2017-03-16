import sys
import itertools
import numpy as np
import math
from copy import copy
f=open(sys.argv[1],'r')
ncases=int(f.readline().strip('\n'))
def isFAS(x):
  xs=repr(x)
  if int(x)!=x or xs!=xs[::-1]:
    return False
  sr=sqrt(x)
  ssr=repr(int(sr))
  if int(sr)!=sr or ssr!=ssr[::-1]:
    return False
  return True

def sqisFAS(x):
  xs=repr(x)
  if int(x)!=x or xs!=xs[::-1]:
    return 0
  sq=x*x
  ssq=repr(int(sq))
  if int(sq)!=sq or ssq!=ssq[::-1]:
    return 0
  return 1
  
for icase in xrange(ncases):
  A,B=[int(x) for x in f.readline().strip().split()]
  #Only need to look at integers from floor(sqrt(A))-floor(sqrt(B))
  ctr=0
  for i in xrange(int(np.ceil(np.sqrt(A))),int(np.floor(np.sqrt(B))+1)):
    #t=sqisFAS(i)
    #if t==1:
    #  print "Winner %d %d"%(i,i*i)
    ctr=ctr+sqisFAS(i)
  print "Case #%d: %d"%(icase+1,ctr)
