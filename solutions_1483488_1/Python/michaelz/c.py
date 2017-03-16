#!/usr/bin/env python

def pairs_for(s, A, B):
  n = int(s)
  counter = 0
  pairs = []
  for i in xrange(len(s) - 1):
    s = s[-1]+s[:-1]
    m = int(s)
    pair = (n, m)
    if n < m and m <= B and n >= A and pair not in pairs:
      pairs.append(pair)
      counter += 1
  return counter

cases = int(raw_input())
for i in xrange(1, cases+1):
  print 'Case #%d:' % i,
  A, B = [int(i) for i in raw_input().split(' ')]
  counter = 0
  for n in xrange(A, B+1):
    counter += pairs_for(str(n), A, B)
  print counter
