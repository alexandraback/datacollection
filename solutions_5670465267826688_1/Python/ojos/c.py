#!/usr/bin/env python

# (result, neg?)
mul = [ [(0,0), (1,0), (2,0), (3,0)],
        [(1,0), (0,1), (3,0), (2,1)],
        [(2,0), (3,1), (0,1), (1,0)],
        [(3,0), (2,0), (1,1), (0,1)] ]
d = { 'i':1, 'j':2, 'k':3 }

for nnn in xrange(1, int(raw_input())+1):
  print "Case #%d:" % (nnn),
  L, X = [int(x) for x in raw_input().split()]
  ex = [d[x] for x in raw_input()]
  le, end = len(ex), len(ex) * X

  reducible, s, neg, found = 0, 0, 0, 0
  for i in xrange(min(4*le, end)):
    s, n = mul[s][ex[i%le]]
    neg ^= n
    if (s,neg) == (1,0):
      found, index = 1, i+1
      break

  if found:
    s, neg, found = 0, 0, 0
    for i in xrange(index, min(index+4*le, end)):
      s, n = mul[s][ex[i%le]]
      neg ^= n
      if (s,neg) == (2,0):
        found, index = 1, i+1
        break

    if found:
      start_X = index / le
      num_X = (X - start_X - 1) % 4
      index %= le

      s, neg = 0, 0
      for i in xrange(index, le):
        s, n = mul[s][ex[i]]
        neg ^= n

      single, single_neg = 0, 0
      for i in xrange(index):
        single, n = mul[single][ex[i]]
        single_neg ^= n
      single, n = mul[single][s]
      single_neg ^= neg ^ n

      for i in xrange(num_X):
        s, n = mul[s][single]
        neg ^= single_neg ^ n

      if (s,neg) == (3,0):
        reducible = 1

  print "YES" if reducible else "NO"

