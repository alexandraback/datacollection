#!/usr/bin/python
import sys

def calc(K, C, S):
  certs = range(1, S+1)
  return " ".join(str(cert) for cert in certs)
  return "IMPOSSIBLE"

def main():
  d = file(sys.argv[1]).readlines()
  n = int(d[0])
  for j in xrange(1,n+1):
    K, C, S = [int(el) for el in d[j].split()]
    print "Case #%d: %s" % (j, calc(K, C, S))

main()
