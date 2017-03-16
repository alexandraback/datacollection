#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import math

def find_offset(K, C, start):
  offset = start
  for k in xrange(1, C):
    offset = K*(offset-1) + start + k
  return offset

def find_offset_end(K, C, start, r):
  offset = start
  for k in xrange(1, r):
    offset = K*(offset-1) + start + k
  for k in xrange(r, C):
    offset = K*offset
  return offset

def solve(t, i):
  K, C, S = map(int, t.split(' '))
  if C == 1:
    if S < K:
      print 'Case #%d: IMPOSSIBLE'%i
    else:
      res = ''
      for k in xrange(1, K+1):
        res += ' ' + str(k)
      print 'Case #%d:%s'%(i, res)
    return

  if S < math.ceil(K*1./C):
    print 'Case #%d: IMPOSSIBLE'%i
    return

  if K == 2:
    print 'Case #%d: 2'%i
    return

  if K == 3:
    if S < (K+1-C):
      print 'Case #%d: IMPOSSIBLE'%i
    elif C == 2:
      print 'Case #%d: 2 3'%i
    else:
      print 'Case #%d: 6'%i
    return

  start = 1
  res = ''
  while start <= (K-C):
    res += ' ' + str(find_offset(K, C, start))
    start += C
  if start <= K:
    res += ' ' + str(find_offset_end(K, C, start, K-start+1))
  print 'Case #%d:%s'%(i, res)

if __name__ == "__main__":
  with open(sys.argv[1]) as f:
    buf = f.read()
  t = buf.split("\n")
  nb_tests = int(t[0])
  t = t[1:]
  for k in xrange(0, nb_tests):
    solve(t[k], k+1)
