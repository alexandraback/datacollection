#!env python

import sys;
import math;

def main():
    line  = sys.stdin.readline()
    words = line[:-1].split(' ')
    T = int( words[0] )

    c = 0;
    while 1:
        c += 1
        if c > T :
            break

        line  = sys.stdin.readline()
        words = line[:-1].split(' ')
        r = int( words[0] )
        t = int( words[1] )

        print "Case #%d: %d" % (c,ans(r,t))

def ans(r,t):
    n = ((-2*r+1) + intsqrt((2*r-1)*(2*r-1)+8*t))/4.0

    return int(n)

def intsqrt(x):
  a = 0
  c = 0
  y = 0
  i = 0
  t = x;

  while t > 0:
      t = t >> 1
      i += 1

  i += i & 1
  for j in range(i,-2,-2):
    c = (y << 1 | 1) <= (x >> j)
    d = 0
    if c :
        d = 1
    a = a << 1 | d
    y = y << 1 | d
    x -= d * y << j
    y += d;

  return a;



if __name__ == '__main__':
    main()

