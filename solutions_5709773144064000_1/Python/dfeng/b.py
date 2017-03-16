from __future__ import division
import math
from numpy import arange

fname = "B-large.in"
# fname = "test.in"

def solve(C,F,X):
  # check that X > C
  if X <= C:
    return X / 2
  xc = X - C

  z = X/C - 2/F - 1
  # print z
  # z = max(math.ceil(z), 0)
  if z < 0:
    return X / 2
  z = math.ceil(z)
  # print z

  # r = arange(2, 2+(z+1)*F, F)
  ra = xrange(0, int(z)+1)
  su = sum([1/(2 + k*F) for k in ra])
  # r = arange(2, 2+int((z+1)*F), int(F))
  # print r
  # print C, sum([1/j for j in r]), xc, 2 + z*F
  return C * su + xc/(2 + z*F)

def main():
  with open(fname) as f:
    for i in xrange(int(f.readline())):
      C, F, X = map(float, f.readline().split())
      print 'Case #%s: %s' % (i + 1, solve(C,F,X))
  
main()