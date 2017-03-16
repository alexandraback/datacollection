import sys

def main():
  nc = int(sys.stdin.next())
  for cNum in xrange(1, 1+nc):
    r, t = map(int, sys.stdin.next().split())

    lo, hi = 1, 2
    while canDraw(r, t, hi):
      lo, hi = hi, 2*hi

    while hi-lo > 1:
      mid = (lo + hi) // 2
      if canDraw(r, t, mid):
        lo = mid
      else:
        hi = mid

    print "Case #{0}: {1}".format(cNum, lo)

def canDraw(r, t, k):
  return k*(2*r + 2*k - 1) <= t

if __name__=="__main__": sys.exit(main())

