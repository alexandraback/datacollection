from __future__ import division
import math
import numpy as np

fname = "C-small-attempt8.in.txt"
# fname = "test.in"

def solve(R,C,M):
  total = R*C
  empty = total - M

  if empty == 1:
    mat = np.matrix(["*" for y in xrange(R*C)]).reshape(R,C)
    mat[0,0] = "c"
    return prnt(mat)
  if total == M:
    return "Impossible"

  if min(R,C) == 1:
    mat = np.matrix(["." for y in xrange(R*C - M)] + ["*" for y in xrange(M)]).reshape(R,C)
    mat[0,0] = "c"
    return prnt(mat)

  elif min(R,C) == 2:
    if M % 2 == 1 or empty < 4:
      return "Impossible"
    else:
      mat = np.matrix(["." for y in xrange(R*C - M)] + ["*" for y in xrange(M)]).reshape(max(R,C), 2)
      mat[0,0] = "c"
      if R == 2:
        mat = mat.transpose()
      return prnt(mat)

  elif min(R,C) >= 3:
    mat = np.matrix(["*" for y in xrange(R*C)]).reshape(R,C)
    if empty % 2 == 1:
      # create 9
      empty = empty - 9
      padding = 3
    else:
      # center 4
      empty = empty - 4
      padding = 2

    mat[:padding, :padding] = np.matrix(["." for y in xrange(padding*padding)]).reshape(padding,padding)
    mat[0, 0] = "c"

    if empty < 0:
      return "Impossible"

    # start populating rows
    
    if empty - (C-padding) * 2 <= 0:
       mat[:2,padding:] = np.matrix(["." for y in xrange(empty)] + ["*" for y in xrange((C-padding) * 2 - empty)]).reshape(C-padding, 2).transpose()
       return prnt(mat)
    else:
      mat[:2,padding:] = np.matrix(["." for y in xrange((C-padding) * 2)]).reshape(C-padding, 2).transpose()

    # popluate columns
    empty = empty - (C-padding) * 2
    if empty - (R-padding) * 2 <= 0:
      mat[padding:,:2] = np.matrix(["." for y in xrange(empty)] + ["*" for y in xrange((R-padding) * 2 - empty)]).reshape(R-padding, 2)
      return prnt(mat)
    else:
      mat[padding:,:2] = np.matrix(["." for y in xrange((R-padding) * 2)]).reshape(R-padding, 2)

    empty = empty - (R-padding) * 2
    # print prnt(mat)
    # print padding, R, C, M, empty
    if padding == 3:
      mat[2:,2:] = np.matrix(["."] + ["." for y in xrange(empty)] + ["*" for y in xrange((R-2)*(C-2) - empty - 1)]).reshape(R-2, C-2)
    else:
      mat[padding:,padding:] = np.matrix(["." for y in xrange(empty)] + ["*" for y in xrange((R-padding)*(C-padding) - empty)]).reshape(R-padding, C-padding)
    
    return prnt(mat)

def prnt(M):
  return "\n".join(["".join(x) for x in M.tolist()])

def main():
  with open(fname) as f:
    for i in xrange(int(f.readline())):
      R,C,M = map(int, f.readline().split())
      print 'Case #%s:' % (i + 1)
      # print R,C,M
      print solve(R,C,M)
  
main()