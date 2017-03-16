import sys
import math
import bisect

def isPalindrome(n):
  s = str(n)
  return s == s[::-1]

with open(sys.argv[1],"r") as f:
  # Precomputation
  l = []
  M = pow(10,16)
  for i in xrange(1,int(math.ceil(math.sqrt(math.sqrt(M))))):
    s = str(i)
    n = int(s+s[::-1])
    N = n*n
    if isPalindrome(N):
      l.append(N)
    s = str(i)
    n = int(s[:-1]+s[::-1])
    N = n*n
    if isPalindrome(N):
      l.append(N)
  l.sort()
  # Read input
  T = int(f.next())
  for k in xrange(T):
    dim = f.next().split()
    A = int(dim[0])
    B = int(dim[1])
    low = bisect.bisect_left(l,A)
    high = bisect.bisect_right(l,B)
    print "Case #" + str(k+1) + ": " + str(high-low)