#!/usr/bin/python2
#-*- coding: utf-8 -*-

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

def f(r, N):
  return 2*N*N + N*2 + (N+1)*(2*r+1)

for test in range(readint()):
  print 'Case #%i:'%(test+1),
  r, t = readarray(int)

  a = 0
  b = t

  while a + 1 < b:
    m = (a+b)/2
    v = f(r, m)
    if v <= t:
      a = m
    elif v > t:
      b = m
  print b
