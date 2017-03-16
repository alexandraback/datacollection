#!/usr/bin/python -tt

def main(A, B, K):
  count = 0
  for i in xrange(A):
    for j in xrange(B):
      if i&j < K: count +=1
  return count


if __name__ == '__main__':
  import sys
  T = int(sys.stdin.readline())
  for i in xrange(T):
    A, B, K = map(int, sys.stdin.readline().split())
    res = main(A, B, K)
    print "Case #%d: %s" % (i + 1, res)

