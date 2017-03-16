from math import *

t= int(pow(2,40))
n= int(raw_input())

for i in xrange(n):
  p,q= raw_input().split('/')
  # print p,q
  p=int(p)
  q=int(q)
  if (t*p)%q!=0:
    print "Case #%d: impossible"%(i+1)
  else:
    s= int(log(t*p/q,2))
    print "Case #%d: %d"%((i+1),(40-s))
