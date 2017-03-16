#!/usr/bin/python

import sys

def toInt(a):
  return int(a)



import sys

N = int(sys.stdin.readline())
#print N
for test in range(0, N):
  levelN = int(sys.stdin.readline())
#  print levelN
  stars = []
  for level in range(0, levelN):
    t = sys.stdin.readline().rstrip('\n').split()
    stars.append((int(t[0]), int(t[1])))
  stars.sort(lambda x, y: x[1] - y[1] or x[0] - y[0])
#  print stars
  getstars = 0
  match = 0
  while stars:
    nohit = 1
#    print test,":",getstars,":",stars
    for i in range(0, len(stars)):
      if stars[i][1] <= getstars:
        if stars[i][0] == 1000000000:
          getstars = getstars + 1
        else:
          getstars = getstars + 2
        match = match + 1
        del(stars[i])
        nohit = 0
        break
    if nohit > 0:
      n = len(stars) - 1
      for i in range(0, len(stars)):
        if stars[n-i][0] <= getstars:
          stars[n-i] = (1000000000, stars[n-i][1])
          getstars = getstars + 1
          match = match + 1
          nohit = 0
          break
      if nohit > 0:
        getstars = -1

    if getstars < 0:
      break
  if getstars >= 0:
    print "Case #%d: %d" % (test+1, match)
  else:
    print "Case #%d: Too Bad" % (test+1)
#  print stars
