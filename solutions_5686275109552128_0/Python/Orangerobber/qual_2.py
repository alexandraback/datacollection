import sys
from math import ceil
from collections import *

T = int(sys.stdin.readline())

def exp_value(p_i):
  if(len(p_i) == 0):
    return 0
  m = max(p_i)
  if(m == 1):
    return 1
  if(m == 2):
    return 2
  n_m = p_i[m]
  
  a = m
  for r in range(2, m/2+1):
    #print m, r
    special = p_i.copy()
    special[m-r] += special[m]
    special[r] += special[m]
    del special[m]
    a = min(exp_value(special) + n_m, a)
  return a

for t in range(T):
  d = int(sys.stdin.readline())
  p_i = [int(x) for x in sys.stdin.readline().split()]
  #print t, p_i
  print "Case #%d: %d"%(t+1, exp_value(Counter(p_i)))








