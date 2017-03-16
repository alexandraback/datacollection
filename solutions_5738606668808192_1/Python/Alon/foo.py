#!/usr/bin/python
import sys
from math import sqrt

def calc(N, J):
  mmm = 2**(N/2)
  sieve = [True] * mmm
  for i in xrange(2, mmm):
    if not sieve[i]:
      continue
    for j in xrange(2*i, mmm, i):
      sieve[j] = False

  primes = [i for i,prime in enumerate(sieve) if prime]

  ret = ""
  vals = [False] * N
  vals[0] = True
  vals[-1] = True

  while J:
    for i in xrange(N-2, 0, -1):
      vals[i] = not vals[i]
      if vals[i]:
	break
    certs = []
    for base in xrange(2, 11):
      num = 0 
      for i, val in enumerate(vals):
	num += base ** (i) * int(val)

      for p in primes[2:]:
	if num > p and num % p == 0:
	  certs.append(p)
	  break
      else:
	break
    else:
      ret += "\n"
      ret += "".join([str(int(val)) for val in vals[::-1]])
      ret += " " + " ".join(str(cert) for cert in certs)
      J -= 1

  return ret

def main():
  d = file(sys.argv[1]).readlines()
  n = int(d[0])
  for j in xrange(1,n+1):
    N, J = [int(el) for el in d[j].split()]
    print "Case #%d: %s" % (j, calc(N, J))

main()
