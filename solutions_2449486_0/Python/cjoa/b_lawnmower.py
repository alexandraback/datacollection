#!/usr/bin/env python

from sys import stdin

def check(A):
   N = len(A)
   M = len(A[0])
   max_row = [ max( [ A[i][j] for j in xrange(M) ] ) for i in xrange(N) ]
   max_col = [ max( [ A[i][j] for i in xrange(N) ] ) for j in xrange(M) ]
   return all( [ A[i][j] == max_row[i] or A[i][j] == max_col[j] for i in xrange(N) for j in xrange(M) ] )


def main():
   TC = int(stdin.readline().strip())
   for tc in xrange(1, TC+1):
      N, M = map(int, stdin.readline().split(' '))
      A = []
      for i in xrange(N):
         A.append( map(int, stdin.readline().split(' ')) )
      print 'Case #%d: %s' % (tc, "YES" if check(A) else "NO")
   return 0

if __name__ == '__main__': main()
