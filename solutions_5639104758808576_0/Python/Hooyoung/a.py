#!/usr/bin/python

T = int(raw_input())

for t in xrange(T):
  smax,s = raw_input().split()
  n = 0
  a = 0
  for i,c in enumerate(s):
    c = int(c)
    if n < i:
      a += i-n
      n = i
    n += c
  print "Case #%d: %d" % (t+1,a)


