import sys
import math

def isPalindrome(n):
  s = str(n)
  return s == s[::-1]

def test(f,k):
  dim = f.next().split()
  A = int(dim[0])
  B = int(dim[1])
  cnt = 0
  N = int(math.ceil(math.sqrt(A)))
  while True:
    S = N*N
    if S > B:
      return cnt
    if isPalindrome(N) and isPalindrome(S):
      cnt += 1
    N += 1

with open(sys.argv[1],"r") as f:
  T = int(f.next())
  for k in xrange(T):
    print "Case #" + str(k+1) + ": " + str(test(f,k))