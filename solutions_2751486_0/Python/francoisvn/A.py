#!/usr/bin/python

import sys

vowels = "aeiou"

def con_vowels(S):
  t = 0
  m = 0
  for c in S:
    if c not in vowels:
      t += 1
      if t > m:
        m = t
    else:
      t = 0
  return m

def get_n_val(S,N):
  l = len(S)
  x = 0
  for i in range(l):
    for j in range(i+1,l+1):
      sub = S[i:j]
      cv = con_vowels(sub)
      # print sub,cv
      if cv >= N:
        x += 1
        # print sub
  return x

T = int(sys.stdin.readline())
for t in range(T):
  # print >> sys.stderr, "Test: %d" % (t+1)
  toks = sys.stdin.readline().strip().split()
  S = toks[0].lower()
  N = int(toks[1])

  # print S,N

  X = get_n_val(S,N)

  print "Case #%d: %d" % (t+1,X)

