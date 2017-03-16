# -*- coding: utf-8 -*-
# Google Code Jam 2012
# Round1A B

import sys

def ReadInts():
  line = sys.stdin.readline().rstrip().split()
  return map(int,line)

def cmplevel2(i,j):
  if i[1] < j[1]:
    return -1
  elif i[1] == j[1]:
    return 0
  else:
    return 1

def cmplevel1(i,j):
  if i[0] < j[0]:
    return -1
  elif i[0] == j[0]:
    return 0
  else:
    return 1

def solve(N,levels):
  levels.sort(cmp=cmplevel2)
  times = 0
  stars = 0
  level1_clear = []
  while levels:
    levels.sort(cmp=cmplevel2)
    if levels[0][1] <= stars:
#      print levels[0],2
      times += 1
      if levels[0][2] in level1_clear:
        stars += 1
      else:
        stars += 2
      levels.pop(0)
    else:
      required = levels[0][1] - stars
      levels.sort(cmp=cmplevel1)
      if required > len(levels):
        return -1
      n = len(levels)
      while required > 0:
        n -= 1
        if n < 0:
          return -1
        if (not levels[n][2] in level1_clear) and levels[n][0] <= stars:
#          print levels[n],1
          times += 1
          stars += 1
          level1_clear.append(levels[n][2])
          required -= 1
          n = len(levels)

  return times


def main():
  T = ReadInts()[0]
  for t in xrange(1,T+1):
    N = ReadInts()[0]
    levels = []
    for i in xrange(N):
      a,b = ReadInts()
      levels.append([a,b,i])
    ans = solve(N,levels)
    if ans >= 0:
      print "Case #%d: %d"%(t,ans)
    else:
      print "Case #%d: Too Bad"%(t)
    
if __name__ == "__main__":
  main()
  
