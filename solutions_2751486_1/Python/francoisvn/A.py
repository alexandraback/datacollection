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

def get_con_list(S):
  L = []
  connow = False
  constart = 0
  for i in range(len(S)):
    c = S[i]
    if c not in vowels:
      if not connow:
        connow = True
        constart = i
    else:
      if connow:
        L.append([constart,i-1])
      connow = False
  if connow:
    L.append([constart,i])
  return L

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
        print sub
  return x

T = int(sys.stdin.readline())
for t in range(T):
  # print >> sys.stderr, "Test: %d" % (t+1)
  toks = sys.stdin.readline().strip().split()
  S = toks[0].lower()
  N = int(toks[1])

  # print S,N

  # X = 0
  # if con_vowels(S) >= N:
  #   X = get_n_val(S,N)
  # get_n_val(S,N)

  cs = get_con_list(S)
  lcs = []
  for con in cs:
    if (con[1]-con[0]+1) >= N:
      lcs.append(con)

  # print lcs

  X = 0
  lastc = 0
  L = len(S)
  for con in lcs:
    s = con[1] - con[0] + 1
    l = L - con[0]
    m = con[0] - lastc
    d = s - N
    x = (d + 1)*(l - s + 1) + (d+1)*d/2 # !!!...
    # xx = (m+1) * x # ...!!!...
    # xx = (s-N+1) * x
    xx = x + m*(l - N + 1)
    X += xx
    # print con,s,l,m,d,xx
    lastc = con[0] + d + 1


  print "Case #%d: %d" % (t+1,X)

