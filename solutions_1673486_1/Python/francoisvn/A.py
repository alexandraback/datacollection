#!/usr/bin/python

import sys

def finishtyping(A,B,p):
  ppi=1.0
  for pi in p:
    ppi*=pi

  t1=(B-A+1)*ppi
  t2=(2*B-A+2)*(1-ppi)
  return t1+t2

def nbackspaces(A,B,ppitbl,n):
  ppi=ppitbl[A-n-1]

  t1=(B-A+1+2*n)*ppi
  t2=(2*B-A+2+2*n)*(1-ppi)
  return t1+t2

T = int(sys.stdin.readline())
for i in range(T):
  toks1 = sys.stdin.readline().strip().split()
  A = int(toks1[0])
  B = int(toks1[1])

  toks2 = sys.stdin.readline().strip().split()
  p = []
  for pi in toks2:
    p.append(float(pi))

  #print A,B,p

  C = B+2 # enter first
  C = min(C,finishtyping(A,B,p))

  ppi=[p[0]]
  for j in range(1,A):
    ppi.append(ppi[j-1]*p[j])

  #print ppi

  for n in range(1,A/2+1):
    C = min(C,nbackspaces(A,B,ppi,n))

  print "Case #%d: %.6f" % (i+1,C)

