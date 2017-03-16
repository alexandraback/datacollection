#!/usr/bin/python

import sys


def merge(G, (a,b)):
  if len(G) and a == G[-1][1]+1:
      G[-1] = (G[-1][0], b)
  else:
    G.append((a,b))


def nextG(G, p):
  a = None
  pos = -1
  e = p
  while p+1 > e and pos+1 < len(G):
    pos += 1
    (s, e) = G[pos]

  if pos < len(G):
    if s <= p and e > p:
      a = p+1
    elif s > p:
      a = s

  return a

def nextGs(Gs, p):
  a = None
  for i in xrange(len(Gs)):
    g = nextG(Gs[i], p)
    if g is not None and (a is None or g < a):
      a = g

  return a

def reduceGs(Gs, t):
  for i in xrange(len(Gs)):
    G1 = []
    for c in t:
      if nextG(Gs[i], c-1) == c:
        merge(G1, (c, c))
    Gs[i] = G1[:]

def filter2(Gs, candidates):
  for G in Gs:
    found = False
    for i in candidates:
      if i == -1:
        continue
      if nextG(G, i-1) == i:
        found = True
    if not found:
      return False
  return True


def filter(Gs, K, C, S):
  #print Gs
  #print "filter Gs", Gs
  t = []
  candidates = [-1,]
  i = 0
  while not filter2(Gs, candidates):
    candidates[i] = nextGs(Gs, candidates[i])
    if candidates[i] is not None:
      if i+1 < S:
        candidates.append(candidates[i])
        i += 1
    elif i > 0:
      i -= 1
      candidates.pop()
    else:
      candidates.pop()
      break

  #print t
  return candidates

def case(K, C, S):
  Gs = []
  for i in xrange(K):
    G = []
    # 1 gold in position i
    if C == 1:
      merge(G, (i, i))
    else:
      for j in xrange(K):
        # position the gold in the artwork
        if C == 2:
          a = j*K
        else:
          a = j*((K**(C-1))+K**(C-2))
        #print K,j,a
        if i == j:
          merge(G, (a, a+K-1))
        else:
          merge(G, (a+i,a+i))
    Gs.append(G)
  t = filter(Gs, K, C, S)
  if len(t):
    return ' '.join(map(lambda x: '%d'%(x+1), t))
  else:
    return 'IMPOSSIBLE'

f = open(sys.argv[1])
T = int(f.readline())
for i in xrange(T):
  (K, C, S) = map(int, f.readline().split())
  print "Case #%d: %s"%(i+1, case(K, C, S))

