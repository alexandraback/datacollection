#!/usr/bin/python -tt

def main(pattern):
  N = len(pattern)
  M = len(pattern[0])
  for i in xrange(N):
    for j in xrange(M):
      h = pattern[i][j]

      row = 0
      column = 0
      #if height in row > (i,j) AND height in column > (i,j) => return NO
      #row
      for k in xrange(M):
        if pattern[i][k] > h: row = 1
        
      #column
      for k in xrange(N):
        if pattern[k][j] > h: column = 1

      if row and column: return "NO"

  #else
  return "YES"


if __name__ == '__main__':
  import sys
  T = int(sys.stdin.readline())
  for i in xrange(T):
    N,M = map(int,sys.stdin.readline().strip().split(" "))
    pattern = []
    for j in xrange(N):
      pattern.append(map(int,sys.stdin.readline().strip().split(" ")))
    res = main(pattern)
    print "Case #%d: %s" % (i + 1, res)



