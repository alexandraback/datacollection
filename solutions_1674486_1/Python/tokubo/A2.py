#!/usr/bin/python

import sys

def toInt(a):
  return int(a)

import sys

T = int(sys.stdin.readline())
#print N
for test in range(T):
  N = int(sys.stdin.readline())
  M = []
  for i in range(N):
    t = map(toInt, sys.stdin.readline().rstrip('\n').split())
    M.append(map(lambda x: x-1, t[1:]))

  C = {}
  def getsets(i):
    if i in C:
      return C[i]
    if M[i] == []:
      result = set([i])
      C[i] = result
      return result
    result = set([])
    for m in M[i]:
      result = result | getsets(m)
    C[i] = result
    return result

  diamond = 0
  for i in range(N):
    sets = set([])
    for j in M[i]:
      t = getsets(j)
      if sets & t:
        diamond = 1
        break
      sets = sets | t

  if diamond:
    print "Case #%d: Yes" % (test+1)
  else:
    print "Case #%d: No" % (test+1)
#  print stars
