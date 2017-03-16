#!/usr/bin/env python

import sys

def rl():
  return sys.stdin.readline().strip()

def solve_one():
  A=int(rl().split(' ')[0])
  B=A
  sizes = map(int, rl().split(' '))
  sizes.sort()
  cost = [0]
  for i in xrange(len(sizes)):
    if A>sizes[i]:
      A += sizes[i]
      cost.append(cost[-1])
    else:
      lcost=0
      if A>1:
        while A<=sizes[i]:
          lcost+=1
          A+=A-1
        A+=sizes[i]
      else:
        lcost=len(sizes)
      cost.append(cost[-1]+lcost)
  ret = cost[-1]
  for i in xrange(len(sizes)):
    ret = min(ret, cost[i]+len(sizes)-i)
  return ret

def main():
  for i in xrange(int(rl())):
    print 'Case #%d: %s' % (i+1,solve_one())

if __name__ == '__main__':
  main()
