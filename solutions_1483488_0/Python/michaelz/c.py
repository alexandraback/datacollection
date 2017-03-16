#!/usr/bin/env python

def assert_recycled(n, m):
  assert sorted(n) == sorted(m)
  assert int(n) < int(m)
  fail = True
  for i in xrange(1, len(n)):
    test_m = n[-i:]+n[:-i]
    if test_m == m:
      fail = False
      break
  if fail:
    print 'Not recycled: (%s, %s)' % (n, m)
    assert not fail
  else:
    print 'Recycled: (%s, %s)' % (n, m)

def pairs_for(s, A, B):
  digits = sorted(s)
  n = int(s)
  counter = 0
  for i in xrange(len(s) - 1):
    s = s[-1]+s[:-1]
    m = int(s)
    if n < m and m <= B and n >= A:
      #assert_recycled(str(n), str(m))
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
