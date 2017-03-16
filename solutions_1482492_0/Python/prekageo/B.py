#!/usr/bin/env python

import sys
import math

def rl():
  return sys.stdin.readline().strip()

def solve_one():
  D,N,A=rl().split()
  D=float(D)
  N=int(N)
  A=int(A)
  t=[]
  x=[]
  for i in xrange(N):
    tt,xx=map(float,rl().split())
    t.append(tt)
    x.append(xx)
  a=map(float,rl().split())
  res=[]
  def go(a):
    tt = math.sqrt(2*D/a)
    if len(x)==2:
      ttt = (D-x[0])/(x[1]-x[0])*(t[1]-t[0])
    else:
      ttt=t[0]
    tt = max(tt,ttt)
    return tt
  for aa in a:
    v=go(aa)
    res.append(go(aa))
  return '\n' + '\n'.join('%f' % x for x in res)

def main():
  T = int(rl())
  for i in xrange(T):
    #sys.stderr.write('%d\n'%i)
    print 'Case #%d: %s' % (i+1,solve_one())

if __name__ == '__main__':
  main()
