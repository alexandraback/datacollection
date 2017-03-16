#!/usr/bin/env python

from sys import stdin

def main():
   TC = int(stdin.readline().strip())
   for tc in xrange(1, TC+1):
      M, S = stdin.readline().split()
      res = 0
      num_standing = 0
      for k, f in enumerate(S):
         f = int(f)
         if f == 0: continue
         add = max(k - num_standing, 0)
         res += add
         num_standing += add + f
      print 'Case #%d: %d' % (tc, res)
   return 0

if __name__ == '__main__': main()
