#!/usr/bin/python
import sys

def calc(A, B, p_v):
  mink = (1 + B + 1)

  P = 1
  for i,p in enumerate(p_v):
    P *= p
    back = A-(i+1)
    del_and_cont = 2*back+(B-A)+1.0
    mmm = P*(del_and_cont) + (1-P)*(del_and_cont + B + 1)
    if mink > mmm:
      mink = mmm
  return mink

def main():
  d = file(sys.argv[1]).readlines()
  n = int(d[0])
  for j in xrange(1, n+1):
    A,B = [int(x) for x in d[2*j-1].split(' ')]
    p = [float(x) for x in d[2*j].split(' ')]
    print "Case #%d: %f" % (j, calc(A,B,p))
main()
