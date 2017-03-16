#!/usr/bin/python

import sys

def brute(X,Y):
   if X > 0:
      dir = 'E'
      mag = 1
   else:
      dir = 'W'
      mag = -1
   cur = 1
   x = 0
   while x != X:
      x += ( cur * mag)
      cur += 1
      mag *= -1
      sys.stdout.write(dir)
      if dir == 'E':
         dir = 'W'
      else:
         dir = 'E'

   if Y > 0:
      dir = 'S'
      mag = -1
   else:
      dir = 'N'
      mag = 1
   y = 0
   while y != Y:
      y += ( cur * mag)
      cur += 1
      mag *= -1
      sys.stdout.write(dir)
      if dir == 'N':
         dir = 'S'
      else:
         dir = 'N'
   assert cur <= 500
   print

data = file( sys.argv[1] ).read().splitlines()

l = data.pop( 0 )
NUMCASE = int(l)

for CASE in range(1,NUMCASE+1):
    print 'Case #%d: ' % CASE,
    l = data.pop( 0 )
    X, Y = [ int(x) for x in  l.split(' ')]
    brute(X,Y)
    sys.stdout.flush()



