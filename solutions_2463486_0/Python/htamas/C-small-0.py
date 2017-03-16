#!/usr/bin/env python
from sys import argv
from itertools import chain, combinations

fns = []

#def palindrome(x):
#  return x == int(''.join(reversed(str(x))))

def addfns(x):
  #if not palindrome(x) or not palindrome(x*x):
  #  print "Error: " + str(x)
  #else:
    fns.append(x*x)

addfns(1)
addfns(2)
addfns(3)
for n in xrange(2,51):
  p = [10 ** (n-i-1) + 10 ** i for i in xrange(n//2)]
  c = 10 ** (n//2)
  addfns(2 * p[0])
  if n % 2:
    addfns(2 * p[0] + c)
    addfns(p[0] + 2 * c)
    for i in xrange(1, n//2):
      addfns(p[0] + p[i] + 2 * c)
  for m in chain([[]], combinations(xrange(1, n//2), 1), combinations(xrange(1, n//2), 2), combinations(xrange(1, n//2), 3)):
    t = p[0] + sum(p[i] for i in m)
    addfns(t)
    if n % 2:
      addfns(t + c)

fns.sort()
N = len(fns)

def countless(x):
  u = 0
  v = N
  while u < v:
    w = (u+v)//2
    if fns[w] < x:
      u = w+1
    else:
      v = w
  return u

f = open(argv[1])
f.next()
t = 0
for l in f:
  t += 1
  a, b = map(int, l.strip().split(' '))
  print "Case #%d: %d" % (t, countless(b+1) - countless(a))

