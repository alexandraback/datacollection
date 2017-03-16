#!/usr/bin/python

import sys, math

def calc3(*ar):
  print(ar)

def dump(msg):
  print(msg, file=sys.stderr)
  #pass

def calc(A, ns):
  ns = sorted(ns, key=lambda x: -x)

  smi = len(ns)
  ad  = 0

  if A == 1: return len(ns)

  while len(ns) > 0:
    N = ns[-1]

    if N < A:
      A = A + N
      ns.pop()
    else:
      A = A + A - 1
      ad = ad + 1

    smi = min(smi, ad + len(ns))


  


  return smi

with open(sys.argv[1]) as f:
  for T in range(1,int(f.readline())+1):
    (A, N) = [int(x) for x in f.readline().split()]
    ns = [int(x) for x in f.readline().split()]
    print("Case #%s: %s" % (T, calc(A, ns)))

