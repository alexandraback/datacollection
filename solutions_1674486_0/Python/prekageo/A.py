#!/usr/bin/env python

import sys

def rl():
  return sys.stdin.readline().strip()

def solve_one():
  [N]=map(int,rl().split())
  M=[]
  for i in xrange(N):
    M.append(map(int,rl().split())[1:])
  def go(i):
    count[i]+=1
    for j in M[i]:
      go(j-1)
  for i in xrange(N):
    count=[0]*N
    go(i)
    if (any(x>1 for x in count)):
      return 'Yes'
  return 'No'

def main():
  T = int(rl())
  for i in xrange(T):
    #sys.stderr.write('%d\n'%i)
    print 'Case #%d: %s' % (i+1,solve_one())

if __name__ == '__main__':
  main()
