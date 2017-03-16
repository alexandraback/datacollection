#!/usr/bin/python

import sys

def toInt(a):
  return int(a)
def toFloat(a):
  return float(a)

import sys

N = int(sys.stdin.readline())
#print N
for test in range(0, N):
#  print levelN
  t = sys.stdin.readline().rstrip('\n').split()
  A = toInt(t[0])
  B = toInt(t[1])
  P = map(toFloat, sys.stdin.readline().rstrip('\n').split())
#  print A,B
#  print P

  restType = B-A
  minExpect = 0.0
  # keep typing
  correct = 1.0
  for p in P:
    correct = correct * p
  minExpect = ((B-A)+1)*correct + ((B-A)+1 + B+1)*(1.0-correct)
#  print minExpect

  # type backspace
  for i in range(0, A):
    correct = 1.0
    for j in range(0, i):
      correct = correct * P[j]
    BS = A-i # BackSpace
    #print ",",BS
    expect = (BS*2+(B-A)+1)*correct + (BS*2 + (B-A)+1 + B+1)*(1.0-correct)
    minExpect = min(minExpect, expect)
    #print ":",correct
    #print "--",minExpect

  # ENTER
  expect = 1 + B + 1
  minExpect = min(minExpect, expect)

  print "Case #%d: %.6f" % (test+1, minExpect)
#  print stars
