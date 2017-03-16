#!/usr/bin/env python

for nnn in xrange(1, int(raw_input())+1):
  print "Case #%d:" % (nnn),
  S = raw_input().strip()
  d = {}
  for c in S:
    if c not in d:
      d[c] = 0
    d[c] += 1
  ans = ''
  count = [0] * 10

  if 'Z' in d and d['Z'] > 0:
    d['E'] -= d['Z']
    d['R'] -= d['Z']
    d['O'] -= d['Z']
    count[0] = d['Z']

  if 'W' in d and d['W'] > 0:
    d['T'] -= d['W']
    d['O'] -= d['W']
    count[2] = d['W']

  if 'U' in d and d['U'] > 0:
    d['F'] -= d['U'] 
    d['O'] -= d['U']
    d['R'] -= d['U']
    count[4] = d['U']

  if 'O' in d and d['O'] > 0:
    d['N'] -= d['O']
    d['E'] -= d['O']
    count[1] = d['O']

  if 'X' in d and d['X'] > 0:
    d['S'] -= d['X']
    d['I'] -= d['X']
    count[6] = d['X']

  if 'F' in d and d['F'] > 0:
    d['I'] -= d['F']
    d['V'] -= d['F']
    d['E'] -= d['F']
    count[5] = d['F']

  if 'V' in d and d['V'] > 0:
    d['S'] -= d['V']
    d['E'] -= 2*d['V']
    d['N'] -= d['V']
    count[7] = d['V']

  if 'R' in d and d['R'] > 0:
    d['T'] -= d['R']
    d['H'] -= d['R']
    d['E'] -= 2*d['R']
    count[3] = d['R']

  if 'T' in d and d['T'] > 0:
    count[8] = d['T']

  if 'N' in d and d['N'] > 0:
    count[9] = d['N']/2

  for i in xrange(len(count)):
    ans += str(i) * count[i]

  print ans


