#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import math

def find_div(n):
  found = False
  d = 3
#  while d < math.sqrt(n) and (n % d) != 0:
#    d += 2
#  return d
  primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]
  k = 0
  while k < len(primes) and (n % primes[k]) != 0:
    k += 1
  if k < len(primes):
    return primes[k]
  else:
    return n-1

def get_div(a):
  div = []
  for base in xrange(2, 11):
    n = int(a, base)
    d = find_div(n)
    if (n % d) == 0:
      div.append(d)
    else:
      return []
  return div

def inc(a):
  return bin(int(a, 2) + 2)[2:]

def solve(t, i):
  n, j = map(int, t.split(' '))
  print 'Case #%d:'%i
# building
  a = '1'
  for k in xrange(1, n-1):
    a += '0'
  a += '1'
  
# tests
  k = 0
  while k < j:
    d = get_div(a)
    if d != []:
      print a, ' '.join(map(str, d))
      k += 1
    a = inc(a)

if __name__ == "__main__":
  with open(sys.argv[1]) as f:
    buf = f.read()
  t = buf.split("\n")
  nb_tests = int(t[0])
  t = t[1:]
  for k in xrange(0, nb_tests):
    solve(t[k], k+1)
