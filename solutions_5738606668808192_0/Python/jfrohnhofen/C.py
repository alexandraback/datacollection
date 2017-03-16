#!/usr/bin/python

from sys import stdin as I
import random

def solve(n):
  j, w = I.readline().split()
  N = int(w)
  J = int(j)

  print("Case #%i:" % (n+1))

  for _ in range(N):
    while True:
      s = '1' + ''.join(random.choice(['0', '1']) for _ in range(J - 2)) + '1'
      divisors = validate(s)
      if divisors:
        print("%s %s" % (s, ' '.join(map(str, divisors))))
        break

def validate(s):
  divisors = []
  for n in [int(s, i) for i in range(2, 11)]:
    for d in range(2, 10000):
      if n % d == 0 and n != d:
        divisors.append(d)
        break

  if len(divisors) == 9:
    return divisors
  else:
    return None

T = int(I.readline())
for i in range(T):
    solve(i)
