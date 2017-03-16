#!/usr/bin/python2
#-*- coding: utf-8 -*-

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

E = 0
R = 0

# e >= 0
def brute(e, rem):
  if len(rem) == 0:
    return 0
  exc = min(e, max(0, e + R - E))
  best = 0
  for dep in range(exc, e+1):
    best = max(best, rem[0]*dep + brute(min(e-dep+R, E), rem[1:]))
  return best

for test in range(readint()):
  print 'Case #%i:'%(test+1),
  E, R, N = readarray(int)
  V = readarray(int)
  print brute(E, V)
