#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

def clean(t):
  k = len(t)-1
  while t[k] == '+' and k>=0:
    k -= 1
  if k < 0:
    return ''
  else:
    return t[:k+1]

def flip(t):
  res = ''
  for a in t[::-1]:
    if a == '+':
      res += '-'
    else:
      res += '+'
  return res

def step(t):
  if t[0] == '-':
    return clean(flip(t))
  k = 0
  while t[k] == '+':
    k += 1
  return flip(t[:k]) + t[k:]

def solve(t, i):
  stack = clean(t)
  count = 0
  while stack != '':
    stack = step(stack)
    count += 1
  print 'case #%d: %d'%(i, count)

if __name__ == "__main__":
  with open(sys.argv[1]) as f:
    buf = f.read()
  t = buf.split("\n")
  nb_tests = int(t[0])
  t = t[1:]
  for k in xrange(0, nb_tests):
    solve(t[k], k+1)
