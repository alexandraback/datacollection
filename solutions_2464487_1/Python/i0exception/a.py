import os

def needed(r, n):
  return 2*r*n + n + n*(n-1)*2

def solve(r, t):
  lo = 0
  hi = 2**63
  while hi-lo > 5:
    mid = (hi+lo)/2
    x = needed(r, mid)
    if x > t:
      hi = mid-1
    else:
      lo = mid

  while hi != lo:
    if needed(r, hi) <= t:
      return hi
    hi-=1
  return hi

if __name__ == "__main__":
  T = int(raw_input(""))
  for n in range(1, T+1):
    s = raw_input("")
    sarr = s.split(" ");
    r = int(sarr[0])
    t = int(sarr[1])
    print "Case #%d: %d"%(n, solve(r, t))
