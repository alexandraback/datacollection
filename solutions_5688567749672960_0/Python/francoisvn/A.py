#!/usr/bin/python

import sys

cache = { 1:1 }

def rev(n):
  s = str(n)
  rs = s[::-1]
  return int(rs)

def time(n):
  # print >> sys.stderr, "time(%d) = ?" % (n)
  if n <= 20:
    t = n
  elif n in cache:
    t = cache[n]
  elif n % 10 != 0: # don't create leading zeros
    a = time(n-1)
    r = rev(n)
    if r < n: # assumption!!!
      b = time(r)
      t = 1 + min(a,b)
    else:
      t = 1 + a
  else:
    t = 1 + time(n-1)
  cache[n] = t
  # print >> sys.stderr, "time(%d) = %d" % (n, t)
  return t

def count(n):
  for i in range(1,n):
    x = cache[i] # min time to i
    y = 1 + x # time after these moves

    if (i+1) not in cache or cache[i+1] >= y:
      cache[i+1] = y

    r = rev(i)
    if r not in cache or cache[r] >= y:
      cache[r] = y

  return cache[n]

T = int(sys.stdin.readline())
for test in range(T):
  print >> sys.stderr, "Test: %d" % (test+1)
  N = int(sys.stdin.readline().strip())

  # print >> sys.stderr, N
  # t = time(N)
  t = count(N)
  # print >> sys.stderr, t

  print "Case #%d: %d" % (test+1, t)

