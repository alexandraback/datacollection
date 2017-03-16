#!/usr/bin/python

import sys
import math

divisors = []

def get_primes():
  sz = 65536
  v = [False,]*sz
  for d in xrange(2, int(math.sqrt(sz)+1)):
    if v[d]:
      continue
    t = 2*d
    while t < sz:
      v[t] = True
      t += d

  for d in range(2, sz):
    if v[d] == 0:
      divisors.append(d)
  

def jam_str(jam, sep):
  return sep.join(map(lambda x: '%d'%x, jam))

def check(N, jam, base):
  v = 0
  for i in xrange(N-1,-1,-1):
    if jam[i]:
      v += base**(N-i-1)

  for d in divisors:
    if d == v:
      continue
    if v % d == 0:
      return d

  return 0

def forward(N, jam):
  p = N-2
  while p > 0 and jam[p] == 1:
    jam[p] = 0
    p -= 1

  jam[p] = 1

def case(N,J):
  jam = [1,] + [0,]*(N-2) + [1,]
  r = []
  while len(r) < J:
    divs = []

    for base in range(2,11):
      d = check(N, jam, base)
      if d:
        divs.append(d)
      else:
        break

    if len(divs) == 9:
      r.append((jam, divs))
      print '%s %s'%(jam_str(jam, ''), jam_str(divs, ' '))

    forward(N, jam)

get_primes()

f = open(sys.argv[1])
T = int(f.readline())
for i in xrange(T):
  (N, J) = map(int, f.readline().split())
  print "Case #%d:"%(i+1)
  case(N,J)

