import sys
import itertools
import numpy as np
import math
import mpmath as mpm
from copy import copy
mpm.mp.dps = 10000
f=open(sys.argv[1],'r')
ncases=int(f.readline().strip('\n'))
def roots(r,t):
  b=(2.*r-1.)
  d=np.sqrt(8.*t+b**2)
  return .25*(d-b)
for icase in xrange(ncases):
  r,t=[mpm.mpf(x) for x in f.readline().strip().split()]
  b=2.*r-1.
  d=(8.*t+b*b)**.5
  n=.25*(d-b)
  n=int(mpm.floor(n))
  print "Case #%d: %d"%(icase+1,n)
