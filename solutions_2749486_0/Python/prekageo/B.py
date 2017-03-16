#!/usr/bin/env python

import sys

def rl():
  return sys.stdin.readline().strip()

def solve_one():
  def move(dir):
    ret.append(dir)
    if dir == 'E':
      x[0] += d[0]
    elif dir == 'W':
      x[0] -= d[0]
    elif dir == 'N':
      y[0] += d[0]
    else:
      y[0] -= d[0]
    d[0] += 1
  X,Y = map(int,rl().split())
  x,y = [0],[0]
  d = [1]
  ret = []
  while x[0] != X or y[0] != Y:
    dx, dy = X - x[0], Y - y[0]
    if dx > 0:
      if d[0] <= dx:
        move('E')
      else:
        move('W')
        move('E')
    elif dx < 0:
      if d[0] <= -dx:
        move('W')
      else:
        move('E')
        move('W')
    if dy > 0:
      if d[0] <= dy:
        move('N')
      else:
        move('S')
        move('N')
    elif dy < 0:
      if d[0] <= -dy:
        move('S')
      else:
        move('N')
        move('S')
  return ''.join(ret)

def main():
  for i in xrange(int(rl())):
    print 'Case #%d: %s' % (i+1,solve_one())

if __name__ == '__main__':
  main()
