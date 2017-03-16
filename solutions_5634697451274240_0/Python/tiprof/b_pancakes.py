#!/usr/bin/python

import sys

swaps = { '+': '-', '-': '+' }

def positive_tail(S):
  l = 0
  for i in xrange(len(S)-1,-1,-1):
    if S[i] == '+':
      l += 1
    else:
      break

  return l

def negative_head(S):
  l = 0
  for c in S:
    if c == '-':
      l += 1
    else:
      break

  return l

def positive_head(S):
  l = 0
  for c in S:
    if c == '+':
      l += 1
    else:
      break

  return l

def swap(S,n):
  for i in xrange(n//2):
    (S[i], S[n-i-1]) = (swaps[S[n-i-1]], swaps[S[i]])
  if n&1:
    S[n//2] = swaps[S[n//2]]


def case(S):
  l = len(S)
  i = 0
  while positive_head(S) != l:
    i += 1
    if negative_head(S) == 0: 
      swap(S, positive_head(S))
    else:
       swap(S, l-positive_tail(S))

  return i

f = open(sys.argv[1])
T = int(f.readline())
for i in xrange(T):
  S = list(f.readline().strip())
  print "Case #%d: %d"%(i+1, case(S))

