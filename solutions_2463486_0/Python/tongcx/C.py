from sys import stdin
from math import sqrt

def palindrome(n):
  s = str(n)
  for i in xrange(len(s)):
    if s[i] != s[len(s)-i-1]: return False
  return True

def test(n):
  if int(sqrt(n))**2 != n: return False
  k = int(sqrt(n))
  if palindrome(n) and palindrome(k): return True
  return False

T = int(stdin.readline())
for t in xrange(1, T + 1):
  A, B = map(int, stdin.readline().split())
  print 'Case #%d:' % t, sum(test(n) for n in xrange(A, B+1))

