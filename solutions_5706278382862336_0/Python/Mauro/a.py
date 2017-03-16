import math
import itertools
from fractions import gcd

def read_ints():
  return map(int, raw_input().split())

def read_frac():
  return map(int, raw_input().split('/'))

def logb2(x):
  return int(math.log(x) / math.log(2))

def exp2(x):
  log2x = logb2(x)
  if 2**log2x == x:
    return log2x
  else:
    return -1

def solve(a, b):
  g = gcd(a, b)
  a = a / g
  b = b / g
  
  power = exp2(b)
  if power == -1:
    return "Impossible"
  
  ans = power
  while a > 1:
    ans -= 1
    a /= 2
    b /= 2
  
  return ans
  
for test in range(1, int(raw_input()) + 1):
  a, b = read_frac()
  sol = solve(a, b)
  print "Case #%d:" % (test,), sol