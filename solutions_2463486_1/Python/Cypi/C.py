#!/usr/bin/python2
#-*- coding: utf-8 -*-

import math

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

def to_digits(n):
  d = []
  while n > 0:
    d.append(n%10)
    n /= 10
  return d

def is_palindrome(n):
  digits = to_digits(n)
  return list(reversed(digits)) == digits

valid = []

for x in range(1, 10**7+1):
  if is_palindrome(x) and is_palindrome(x*x):
    valid.append(x*x)

for test in range(readint()):
  print 'Case #%i:'%(test+1),
  A, B = readarray(int)
  
  N = 0
  for x in valid:
      if x < A:
        continue
      elif x <= B:
        N += 1
      else:
        break
  print N
