#!/usr/bin/python
#
# Bullseye - Google Code Jam 2013 Round1A A

import sys

inp=sys.stdin
cases=int(inp.readline())
for case in xrange(cases):
  rt=inp.readline().split()
  r=int(rt[0])
  t=int(rt[1])
  #n=(1-2*r+(4*r*r-4*r+1+8*t)**0.5)/4
  #this does not quite work for the big problem because it runs
  #into floating point inaccuracies. But I can only be off by a
  #less than 100 integers, so search for the correct square root.
  rad=4*r*r-4*r+1+8*t
  root=int(rad**0.5)
  while (root+1)**2<=rad:
    root+=1
  while root**2>rad:
    root-=1
  n=(1-2*r+root)/4
  print "Case #"+repr(case+1)+": "+repr(n)
