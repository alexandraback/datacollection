#!/usr/bin/python
import sys

def calc(X,Y):
  seq = ""
  add = "WE" if X > 0 else "EW"
  for i in xrange(abs(X)):
    seq += add
  add = "SN" if Y > 0 else "NS"
  for i in xrange(abs(Y)):
    seq += add
  return seq

def main():
  h = file(sys.argv[1])
  n = int(h.readline())
  for j in xrange(1,n+1):
    X,Y = map(int, h.readline().split(" "))
    print "Case #%d: %s" % (j, calc(X,Y))

main()
