#!/usr/bin/python
import sys

def calc(N):
  if N == 0:
    return "INSOMNIA"

  num = 0
  found = [False]*10

  i = 1
  while True:
    tmp = N*i
    while tmp:
      d = tmp % 10
      if not found[d]:
        found[d] = True
        num += 1
        if num == 10:
          return N*i
      tmp /= 10
    i += 1

def main():
  d = file(sys.argv[1]).readlines()
  n = int(d[0])
  for j in xrange(1,n+1):
    N = int(d[j])
    print "Case #%d: %s" % (j, calc(N))

main()
