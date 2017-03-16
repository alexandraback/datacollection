#!/usr/bin/python
import sys

def calc(A,B):
  count = 0
  l = len(str(A))
  for i in xrange(A,B+1):
    s = str(i)
    seen = set()
    for j in xrange(l-1):
      s = s[1:] + s[0]
      si = int(s)
      if s[0] != '0' and i < int(s) and si <= B and si not in seen:
        seen.add(si)
        count += 1
  return count

def main():
  d = file(sys.argv[1]).readlines()
  n = int(d[0])
  for j in xrange(1, n+1):
    A,B = [int(c) for c in d[j].split()]
    print "Case #%d: %d" % (j, calc(A,B))

main()
