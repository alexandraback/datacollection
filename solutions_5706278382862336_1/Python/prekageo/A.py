#!/usr/bin/env python

import sys
from fractions import gcd
import math

def rl():
  return sys.stdin.readline().strip()

def solve_one():
  p,q=map(int,rl().split('/'))
  x=gcd(p,q)
  p/=x
  q/=x
  if 2**40 % q > 0:
    return 'impossible'
  p*=2**40/q
  p=40-math.floor(math.log(p)/math.log(2))
  return '%d'%p

def main():
  for i in xrange(int(rl())):
    print 'Case #%d: %s' % (i+1,solve_one())

if __name__ == '__main__':
  main()
