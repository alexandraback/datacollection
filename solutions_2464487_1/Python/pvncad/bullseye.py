#/usr/local/bin/python

import sys
import math

T = int(sys.stdin.readline())

for caseno in xrange(T):
   r, t = [int(x) for x in sys.stdin.readline().split()]

   low  = 1
   high = t

   while low < high:
       mid = (low + high) / 2

       area = mid * (2 * r + 1 + (mid - 1) * 2)

       if area <= t:
           low = mid + 1
       else:
           high = mid
   print "Case #%d: %d" % (caseno + 1, low - 1)

