#!/usr/bin/env python

import sys

def rl():
  return sys.stdin.readline().strip()

def solve_one():
  J=map(int,rl().split())[1:]
  S=sum(J)
  ret = []
  def ok(i,j,v):
    #print J,i,j,v
    for i2 in xrange(len(J)):
      if i==i2:
        continue
      vv = j-J[i2]
      #print vv
      if vv > 0:
        k = vv/S
        #print k
        v += k
    #print v
    return v>1
  for i1 in xrange(len(J)):
    a=0.0
    b=1.0
    m=0.5
    while (b-a)>1e-10:
      m=(a+b)/2
      if ok(i1,J[i1]+S*m,m):
        b=m
      else:
        a=m
    ret.append('%f' % (100*m))
  #sys.exit(0)
  return ' '.join(ret)

def main():
  T = int(rl())
  for i in xrange(T):
    print 'Case #%d: %s' % (i+1,solve_one())

if __name__ == '__main__':
  main()
