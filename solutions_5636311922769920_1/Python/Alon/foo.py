#!/usr/bin/python
import sys
from math import ceil

def calc(K, C, S):
  if ceil(float(K)/C) > S:
    return "IMPOSSIBLE"

  certs = []
  curr_pos = 1
  for i in xrange(S):
    d = 0
    for c in xrange(C, 0, -1):
      d += (curr_pos-1)*(K**(c-1))
      curr_pos += 1
      if curr_pos == K+1:
        break
    certs.append(d+1)
    if curr_pos == K+1:
      break

  return " ".join(str(cert) for cert in certs)

def main():
  d = file(sys.argv[1]).readlines()
  n = int(d[0])
  for j in xrange(1,n+1):
    K, C, S = [int(el) for el in d[j].split()]
    print "Case #%d: %s" % (j, calc(K, C, S))

main()
