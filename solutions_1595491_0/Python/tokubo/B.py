#!/usr/bin/python

import sys
import math

def score_tuple(nstr):
  n = int(nstr)
  return (n, int(math.floor((n+2) / 3)), n % 3)

T = int(sys.stdin.readline())
for test in range(0, T):
  tmp = sys.stdin.readline().rstrip('\n').split(' ')
  N = tmp[0]
  S = int(tmp[1])
  p = int(tmp[2])
  scores = map(score_tuple, tmp[3:])
  scores.sort(lambda x, y: y[0] - x[0])
  #print N
  #print S
  #print p
  #print scores

  result = 0
  for score in scores:
    if score[1] >= p:
      result = result + 1
      continue
    if S == 0:
      break
    if score[2] == 1:
      continue
    if score[1] >= p-1 and score[1] != 0:
      S = S-1
      result = result + 1
      continue
  print "Case #%d: %d" % (test+1, result)
