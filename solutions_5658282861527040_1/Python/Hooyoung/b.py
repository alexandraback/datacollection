#!/usr/bin/env python

def gen(A):
  bits = []
  for i in xrange(31,-1,-1):
    if A & (2**i):
      yield(tuple(bits + [0] + [2]*(i)))
    bits.append(1 if (A & (2**i)) else 0)
  yield tuple(bits)

table = [[[1,1,2],[1,0,1],[2,1,3]],[[0,0,0],[0,1,1],[0,1,1]],[[1,1,2],[1,1,2],[2,2,4]]]

def ways(a,b,k):
  nways = 1
  for aa,bb,kk in zip(a,b,k):
    nways *= table[kk][aa][bb]
    if nways == 0: return 0
  return nways

T = int(raw_input())
for t in xrange(T):
  A,B,K = map(int,raw_input().split())
  As = list(gen(A-1))
  Bs = list(gen(B-1))
  Ks = list(gen(K-1))
  out = 0
  for a in As:
    for b in Bs:
      for k in Ks:
        out += ways(a,b,k)
  print 'Case #%d:'%(t+1),out

