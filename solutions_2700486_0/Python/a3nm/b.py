#!/usr/bin/python

import sys

# http://en.wikipedia.org/wiki/Binomial_coefficient
def binomialCoefficient(n, k):
    if k < 0 or k > n:
        return 0
    if k > n - k: # take advantage of symmetry
        k = n - k
    c = 1
    for i in range(1,k+1):
        c = c * (n - (k - i))
        c = c // i
    return c

def f(n, k):
  pfail = 0
  #print "get at least %d succeses in %d tries" % (height, throws)
  for k in range(k):
    pfail += binomialCoefficient(n, k)
  #print pfail

  p = 1.-pfail*(0.5**n)
  return p

lT = sys.stdin.readline()
T = int(lT.strip())
for ncase in range(T):
  l = sys.stdin.readline()
  l.strip()
  x = l.split(' ')
  N = int(x[0])
  X = abs(int(x[1]))
  Y = int(x[2])

  layer = (X+Y)/2
  required = 0
  for i in range(layer):
    required += i*4 + 1
  sufficient = required + layer*4 + 1
  #print required, "required"
  #print sufficient, "sufficient"
  if N <= required:
    print "Case #%d: 0.0" % (ncase+1)
    continue
  if N > sufficient:
    print "Case #%d: 1.0" % (ncase+1)
    continue

  if X == 0:
    # we are last
    print "Case #%d: 0.0" % (ncase+1)
    continue

  height = Y+1
  throws = N-required

  #print "%d throws" % throws
  #print "%d height" % height
  #print "%d Y" % Y

  print "Case #%d: %.8f" % (ncase+1, f(throws, height))

