#!/usr/bin/python
import sys

def calc(pan):
  cnt = 0
  curr = '+'
  for c in pan[::-1]:
    if c != curr:
      cnt += 1
      curr = c

  return cnt

def main():
  d = file(sys.argv[1]).readlines()
  n = int(d[0])
  for j in xrange(1,n+1):
    print "Case #%d: %d" % (j, calc(list(d[j][:-1])))

main()
