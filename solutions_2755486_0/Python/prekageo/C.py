#!/usr/bin/env python

import sys

def rl():
  return sys.stdin.readline().strip()

def solve_one():
  N = int(rl())
  attacks = {}
  wall = {}
  for i in xrange(N):
    d,n,w,e,s,dd,dp,ds = map(int, rl().split())
    for j in xrange(n):
      day = d+j*dd
      if day not in attacks:
        attacks[day] = []
      attacks[day].append((w+j*dp,e+j*dp,s+j*ds))
  ret = 0
  for day in sorted(attacks.keys()):
    attacks_day = attacks[day]
    for attack in attacks_day:
      for x in xrange(attack[0],attack[1]):
        if x not in wall or wall[x] < attack[2]:
          ret += 1
          break
    for attack in attacks_day:
      for x in xrange(attack[0],attack[1]):
        if x not in wall:
          wall[x] = 0
        wall[x] = max(wall[x], attack[2])
  return ret

def main():
  for i in xrange(int(rl())):
    print 'Case #%d: %s' % (i+1,solve_one())

if __name__ == '__main__':
  main()
