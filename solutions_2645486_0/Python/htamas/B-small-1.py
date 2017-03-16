#!/usr/bin/env python

from sys import argv, stderr

E, R = 0, 0
v = []

def findmax(i, j):
  l = 0
  m = 0
  for x in xrange(i, j):
    if v[x] > m:
      l = x
      m = v[x]
  return l, m

def maxinc(i, j):
  #print "maxinc", i, j
  if i == j:
    if R < E:
      stderr.write("Assertion failed\n")
    return 0
  l, m = findmax(i, j)
  e = (l-i+1)*R
  f = (j-l)*R
  r = 0
  if e > E:
    r += maxinc(i, l)
    e = E
  if f > E:
    r += maxinc(l+1, j)
    f = E
  if e+f < E:
    stderr.write("Assertion failed\n")
  r += m * (e+f-E)
  return r

def maxhi(i, j):
  #print "maxhi", i, j
  if i == j:
    return 0
  l, m = findmax(i, j)
  e = (j-l)*R
  if e > E:
    r = m * E
    r += maxhi(i, l)
    r += maxinc(l+1, j)
  else:
    r = m * e
    r += maxhi(i, l)
  return r

def maxlo(i, j):
  #print "maxlo", i, j
  if i == j:
    return 0
  l, m = findmax(i, j)
  e = (l-i+1)*R
  if e > E:
    r = m * E
    r += maxinc(i, l)
    r += maxlo(l+1, j)
  else:
    r = m * e
    r += maxlo(l+1, j)
  return r
  
def maxdec(i, j):
  #print "maxdec", i, j
  if i == j:
    return 0
  l, m = findmax(i, j)
  r = m * E
  r += maxhi(i, l)
  r += maxlo(l+1, j)
  return r

f = open(argv[1])
f.next()
t = 0
for l in f:
  t += 1
  E, R, N = map(int, l.strip().split(' '))
  v = map(int, f.next().strip().split(' '))
  if R > E:
    R = E
  print "Case #%d: %d" % (t, maxdec(0, N))

